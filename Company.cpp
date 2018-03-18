#include "Empresa.h"
#include "Line.h"
#include "Header.h"
#include "Bus.h"
#include<iomanip>

Empresa::Empresa(string nome, string fichCondutores, string fichLinhas){
  

	ifstream myfile(fichCondutores);
	ifstream myfile_line(fichLinhas);

	string line;
	string line_line;

	//DRIVERS//////
	if (myfile.fail()) 
	{
		cerr << "Ficheiro inexistente \n";
		exit(1);
	}
	
	while (getline(myfile, line))
	{
		Driver dr(line);
		
	condutores.push_back(dr);
		}
	myfile.close();

	//LINHAS//////
	if (myfile_line.fail())
	{
		cerr << "Ficheiro inexistente \n";
		exit(1);
	}

	while (getline(myfile_line, line_line))
	{
		Line line (line_line);
		
		linhas.push_back(line);
	}
	myfile.close();

	this->nome = nome;
	this->fichCondutores = fichCondutores;
	this->fichLinhas = fichLinhas;
	
	
	unsigned int i = 0;

	for (i; i < linhas.size(); i++)
	{
		unsigned int numero_buses = number_buses(i);
		unsigned int duraçao, u, soma=0, j;
		unsigned int freq = linhas.at(i).getFrequency();
	
		for (u=0; u < linhas.at(i).getTimings().size(); u++)
		{

			soma += linhas.at(i).getTimings().at(u);
		}
		duraçao = soma * 2;
		
		for (j=0; j < numero_buses; j++)
		{
			Bus bus(j + 1, linhas.at(i).getId(), duraçao, numero_buses, freq);
			buses.push_back(bus);
		}



	}

	







}



unsigned int Empresa::number_buses(unsigned int i)
{
	unsigned int numero, u, freq = linhas.at(i).getFrequency();
	unsigned int soma = 0;
	
	for (u=0; u < linhas.at(i).getTimings().size(); u++)
	{

		soma +=linhas.at(i).getTimings().at(u);
	}
	soma = soma * 2;
	numero = soma / freq;
	if (soma % freq == 0)
	{
		return numero;
	}
	else
	{
		return ++numero;

	}
}












////////////////////////////////
// metodos get
///////////////////////////////
string Empresa::getNome() const{
  return nome;
}

//////////////////////////////
// metodos set
/////////////////////////////

////////////////////////////
// outros metodos
///////////////////////////
void Empresa::distribuiServico(){
}

void Empresa::PesquisaParagem() // FAZER BOLEANA PARA SE NAO ENCONTRAR
{
	vector<int> paragens;
	string paragem;
	cout << "Insira a paragem que quer pesquisar :";
	cin.ignore();
	getline(cin, paragem);

	for (int i = 0; i<linhas.size(); i++)
	{
		for (int u = 0; u < linhas[i].getBusStops().size(); u++)
		{
			if (paragem == linhas[i].getBusStops().at(u))
				paragens.push_back(linhas[i].getId());
		}
	}

	cout << "A paragem " << paragem << " esta incluida nos percursos das linhas com os seguintes id's : ";
	int y = 0;
	if (paragens.size() == 0)
	{
		cout << "A paragem não foi encontrada em nenhum dos percursos. \n";
	}
	else
	{
		cout << paragens[y];
		y++;
		for (y; y < (paragens.size() - 1); y++)
		{
			cout << " , " << paragens[y];
		}

		cout << " e " << paragens[y] << " . " << endl;
	}
	system("pause");

}




void Empresa::menu_linhas() {

	system("cls");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int option;
	cout << "Selecione a opção : \n" << "1-Ver o horario de uma linha \n" << "2-Pesquisar uma paragem \n"<<"3-Distribuição de serviço \n" <<"4-Ver informação de um autocarro \n" << "5-Voltar ao menu principal \n"; 
	cin >> option;
	switch (option) {
	case 1:
		hor_linhas();
		return;
	case 2:
		PesquisaParagem();
		return;
	case 3:
		ver_turnos();
		return;
	case 4:
		ver_inf_bus();
	case 5:
		return;
		
	}
}



// Horario das linhas 
void Empresa::hor_linhas() {

	

	int idd_linha;
	unsigned int i;
	bool validd = false;
	std::cout << "Introduza o número da linha cujo horário deseja visualizar : "; cin >> idd_linha;
	
	int h_inicial, h_final, m_inicial, m_final;
	bool valid = false;




	for (i = 0; linhas.size(); i++)
	{

		if (linhas.at(i).getId() == idd_linha)
		{

			system("cls");
			std::cout << "Linha " << idd_linha << endl;

			h_inicial = 8;
			m_inicial = 0;
			h_final = 21;
			m_final = 0;

			std::cout << endl << setw(10) << endl << "<<< Ida: >>>" << endl << endl;


			for (int k = 0; k < int(linhas[i].getBusStops().size()); k++) {
				if (k == 0) {
					std::cout << setw(5) << " --> " << linhas[i].getBusStops()[k] << ":" << endl << endl;
				}
				else {
					std::cout << setw(5) << " --> " << linhas[i].getBusStops()[k] << ":" << endl << endl;
				}

				int tempo_i = h_inicial * 60 + m_inicial;
				int tempo_f = h_final * 60 + m_final;
				int h = h_inicial, m = m_inicial;
				if (i >= 1) {
					for (int lk = i; lk >= 1; lk--)
						m += linhas[i].getTimings()[lk - 1];
					h = h + m / 60;
					m = m % 60;
					h = h % 24;
				}
				int j = 0;
				while (tempo_i < tempo_f) {
					if (j == 9) {
						j = 0;
						std::cout << endl;
					}
					if (h < 10)
						std::cout << "0";
					std::cout << h << ":";
					if (m < 10)
						std::cout << "0";
					std::cout << m << "   ";
					m = m + int(linhas[i].getFrequency());
					h = h + m / 60;
					m = m % 60;
					h = h % 24;

					tempo_i += int(linhas[i].getFrequency());
					j++;
				}

				std::cout << endl << endl;
			}
			std::cout << endl;
			std::cout << setw(10) << "<<< Volta: >>>";
			std::cout << endl << endl;

			for (int f = int(linhas[i].getBusStops().size()) - 1; f >= 0; f--) {
				if (f == 0) {
					std::cout << setw(5) << " --> " << linhas[i].getBusStops()[f] << ":" << endl << endl;
				}
				else {
					std::cout << setw(5) << " --> " << linhas[i].getBusStops()[f] << ":" << endl << endl;
				}
				int viagem = 0;
				for (int s = 0; s < int(linhas[i].getTimings().size()); s++)
					viagem += linhas[i].getTimings()[s];

				int tempo_i = h_inicial * 60 + m_inicial;
				int tempo_f = h_final * 60 + m_final;
				int h = h_inicial + (viagem / 60);
				int m = m_inicial + (viagem % 60);

				for (int lk = linhas[i].getTimings().size() - 1; lk >= f; lk--)
					m += linhas[i].getTimings()[lk];
				h = h + m / 60;
				m = m % 60;
				h = h % 24;

				int u = 0;
				while (tempo_i < tempo_f) {
					if (u == 9) {
						u = 0;
						std::cout << endl;
					}
					if (h < 10)
						std::cout << "0";
					std::cout << h << ":";
					if (m < 10)
						std::cout << "0";
					std::cout << m << "   ";
					m = m + int(linhas[i].getFrequency());
					h = h + m / 60;
					m = m % 60;
					h = h % 24;

					tempo_i += int(linhas[i].getFrequency());
					u++;
				}
				cout << endl;
			}
			system("pause");
			break;
				}
			}
		}



	
		// Horario das paragens DONE VERRRR
/*void Empresa::hor_paragem() {
	string paragem;
	cout << "Introduza o nome da paragem que pretende ver o horário : "; 
	getline(cin, paragem);
					int contador;
					cout << endl << " <<< " << paragem << " >>>" << endl << endl;
					int siz = horas_paragem.size();

					for (int i = 0; i < siz; i++) {
						cout << " --> Linha " << horas_paragem[i].linha << endl << endl;
						int a = linhas.at(i).getFrequency();
						int freq = a;
						if (a < 0)
							freq = -a;
						contador = (23 - m * 60 )/ freq; //em min
						int cont = all_tempo_linha(horas_paragem[i].linha, fich_linhas);
						int min = horas_paragem[i].minutosApos + 8 * 60;
						for (int j = 0; j < contador * 2; j++) {
							if (j == 0) {
								string a = min2horario(min);
								cout << setw(7) << horas_paragem[i].linha << "  -->  " << a << "   ";
							}
							else if (j % 2 == 0) {
								int as = min + (j / 2)*freq;
								string a = min2horario(as);
								cout << setw(7) << horas_paragem[i].linha << "  -->  " << a << "   ";
							}
							else {
								int extra = tempo_aux(paragem1, horas_paragem[i].linha, fich_linhas);
								int as = min + (j / 2)*freq + extra * 2;
								string a = min2horario(as);
								cout << setw(7) << -horas_paragem[i].linha << "  -->  " << a << endl;
							}
						}
						cout << endl << endl;
					}
				}*/
				
				
			
		