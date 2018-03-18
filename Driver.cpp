#include "Condutor.h"
#include "Empresa.h"
// se houver algum comentario a dizer que ha uma coisa para fazer e no fim desse comentario disser 5/7 significa que ja esta feita



Driver::Driver (string text_line) {

	

	istringstream linha_cond( text_line );
	char p_virgula;          


	linha_cond >> id >> p_virgula;
	linha_cond.ignore();

	char carater;
	carater = linha_cond.get();
	while (carater != ';')
	{
		name = name + carater;
		carater = linha_cond.get();
		
	}
	
	linha_cond.ignore();
	linha_cond >> maxHours >> p_virgula >> maxWeekWorkingTime >> p_virgula >> minRestTime;
	
	
}
Driver::Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime)
{
	this->id = id;
	this->name = name;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	max_week_hours = maxWeekWorkingTime;
	this->minRestTime = minRestTime;


}


void Empresa::menu_conds()
{
	system("cls");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int option;
	cout << "Selecione a opção : \n" << "1-Ver todos os condutores \n" << "2-Pesquisar condutor \n" << "3-Criar condutor \n" <<"4-Ver informação de um condutor \n"<< "5-Voltar ao menu principal \n"; cin >> option;
	switch (option) {
	case 1:
		ler_driv();
		return;
	case 2:
		pesq_driv();
		
		return;
	case 3:
		criar_driv();
		menu_conds();
	case 4:
		ver_inf_driv();
	case 5:
		return;
	}



}


void Empresa::pesq_driv()
{
	system("cls");
		SetConsoleCP(1252);
		SetConsoleOutputCP(1252);
		unsigned int id, i, v, option, option2;
		cout << "Introduza o número identificador do condutor : ";
		cin >> id;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Introduza um número por favor ! \n";
			cin >> id;
		}

		for (i = 0, v = 0; i < condutores.size(); i++)
		{

			if (condutores.at(i).getId() == id)
			{
				v = 0;
				break;
			}
			else
			{
				v = 1;
			}
		}
		if (v == 1)
		{
			cout << "O condutor que pesquisou não se encontra na base de dados, pretende criar o condutor ? \n" << "1-Sim \n" << "2-Não \n";
			cin >> option;
			while (cin.fail() || option < 1 || option > 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Introduza um número válido por favor ! \n";
				cin >> option;
			}
			switch (option)
			{
			case 1:
				criar_driv();
				return;
			case 2:
				menu_conds();
				return;
			}
		}

		cout << "ID: " << condutores.at(i).getId()<< " - " << "Nome: " << condutores.at(i).getName() << " - " << condutores.at(i).getShiftMaxDuration() << " - " << condutores.at(i).getMaxWeekWorkingTime() << " - " << condutores.at(i).getMinRestTime() << endl << endl;
		system("pause");
		cout << "Selecione a opção : \n" << "1-Alterar o condutor \n" << "2-Remover o condutor \n" << "3-Voltar ao menu dos condutores \n" << "4-Voltar ao menu principal \n";
		cin >> option2;
		while (cin.fail() || option2 < 1 || option2 > 4)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Selecione um número válido por favor ! \n";
			cin >> option2;
		}

		cout << endl;
		switch (option2)
		{
		case 1:
			alterar_driv(i);
			return;
			cout << "issa alteration! \n";
			break;
		case 2:
			remover_driv(i);
			return;
			cout << "what in removation... \n";
			break;
		case 3:
			return;
			break;
		case 4:
			return;
			break;
		}


	}


void Empresa::alterar_driv(unsigned int i)
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	unsigned int option, novo_id, novo_turno, novo_turno_semana, novo_descanso;
	string novo_nome;

	cout << "Selecione o que pretende alterar : \n" << "1-Número identificador \n" << "2-Nome \n" << "3-Horas de trabalho/dia (turno) \n" << "4-Horas de trabalho/semana \n" << "5-Mínimo de horas de descanso entre turnos \n";
	cin >> option;
	while (cin.fail() || option < 1 || option > 5)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Introduza um número válido por favor (1 a 5) ! \n";
		cin >> option;
	}
	switch (option)
	{
	case 1:
		cout << "Introduza o número identificador : ";
		cin >> novo_id;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Introduza um número por favor ! \n";
			cin >> novo_id;
		}
		condutores.at(i).setid(novo_id);
		break;
	case 2:
		cout << "Introduza o nome : "; cin.ignore();  getline(cin, novo_nome);
		condutores.at(i).setname(novo_nome);
		break;
	case 3:
		cout << "Introduza o número de horas a trabalhar/dia : "; cin >> novo_turno;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Inroduza um número por favor ! \n";
			cin >> novo_turno;
		}
		condutores.at(i).setmaxHours(novo_turno);
		break;
	case 4:
		cout << "Introduza o número de horas a trabalhar/semana : "; cin >> novo_turno_semana;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Introduza um número por favor ! \n";
			cin >> novo_turno_semana;
		}
		condutores.at(i).setmaxHours_week(novo_turno_semana);
		break;
	case 5:
		cout << "Introduza o número mínmo de horas de descanso entre turnos : "; cin >> novo_descanso;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Introduza um número por favor ! \n";
			cin >> novo_descanso;
		}
		condutores.at(i).setminrest(novo_descanso);
		break;
	}

	int k = 0;
	ofstream myfile;
	myfile.open(fichCondutores);

	for (k; k < (condutores.size() - 1); k++)
	{

		myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getName() << ';' << ' ';
		myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMinRestTime() << endl;


	}
	myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getName() << ';' << ' ';
	myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMinRestTime();

	myfile.close();
}


void Empresa::remover_driv (unsigned int i)
{
	
	condutores.erase(condutores.begin() + i);
	int k = 0;
	ofstream myfile;
	myfile.open(fichCondutores);

	for (k; k < (condutores.size() - 1); k++)
	{

		myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getName() << ';' << ' ';
		myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMinRestTime() << endl;


	}
	myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getName() << ';' << ' ';
	myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMinRestTime();

	myfile.close();
}
		

void Empresa::ler_driv()
{
	
	
	system("cls");
		
		int i;
		for (i = 0; i < condutores.size(); i++)
		{    
			if (condutores.at(i).getmax_week_hours() > 0)
			{
				cout << "ID: " << condutores.at(i).getId() << " - " << "Nome: " << condutores.at(i).getName() << " - " << condutores.at(i).getShiftMaxDuration() << " - " << condutores.at(i).getMaxWeekWorkingTime() << " - " << condutores.at(i).getMinRestTime() << endl;
			}
		}
		system("pause");
	}

void Empresa::criar_driv()
{

	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	system("cls");
	unsigned int id, turno, turno_semana, descanso;
	string nome;
	cout << "Introduza o número identificador do condutor : "; cin >> id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Introduza um numero válido por favor ! \n";
		cin >> id;
	}
	cin.ignore(); cout << endl;
	cout << "Introduza o nome : "; getline(cin, nome);
	cout << endl;
	cout << "Introduza o número de horas a trabalhar por dia : "; cin >> turno;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Introduza um número válido por favor ! \n";
		cin >> turno;
	}
	cout << endl;
	cout << "Introduza o número de horas a trabalhar por semana : "; cin >> turno_semana;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Introduza um número por favor ! \n";
		cin >> turno_semana;
	}
	cout << endl;
	cout << "Introduza o número de horas mínimo de descanso entre turnos : "; cin >> descanso;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Selecione um número válido por favor ! \n";
		cin >> descanso;
	}
	cout << endl;
	Driver dr(id, nome, turno, turno_semana, descanso);
	condutores.push_back(dr);


	int k = 0;
	ofstream myfile;
	myfile.open(fichCondutores);

	for (k; k < (condutores.size() - 1); k++)
	{

		myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getName() << ';' << ' ';
		myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
		myfile << condutores.at(k).getMinRestTime() << endl;


	}
	myfile << condutores.at(k).getId() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getName() << ';' << ' ';
	myfile << condutores.at(k).getShiftMaxDuration() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMaxWeekWorkingTime() << ' ' << ';' << ' ';
	myfile << condutores.at(k).getMinRestTime();

	myfile.close();



}

void Empresa::ver_inf_driv() {




	unsigned int id, i, k;
	cout << "Introduza o número identificador do condutor : "; cin >> id;
	for (i = 0; i < condutores.size(); i++)
	{
		if (condutores.at(i).getId() == id)
		{
			cout << "ID: " << condutores.at(i).getId() << " - " << "Nome: " << condutores.at(i).getName() << " - " << condutores.at(i).getShiftMaxDuration() << " - " << condutores.at(i).getMaxWeekWorkingTime() << " - " << condutores.at(i).getMinRestTime() << endl;
			cout << "Tempo restante de trabalho esta semana(em minutos) : " << condutores.at(i).getmax_week_hours() << endl;
			cout << "Turnos : " << endl;
			for (k = 0; k < condutores.at(i).getShifts().size(); k++)
			{
				unsigned int dia_semana = condutores.at(i).getShifts().at(k).getStartTime() / (60 * 24);
				cout << "Linha : " << condutores.at(i).getShifts().at(k).getBusLineId() << " --> ";
				cout << "Autocarro : " << condutores.at(i).getShifts().at(k).getBusOrderNumber() << " --> ";
				cout << "Hora de início : " << (condutores.at(i).getShifts().at(k).getStartTime() - (dia_semana * 24 * 60)) / 60 << " : " << (condutores.at(i).getShifts().at(k).getStartTime() - (dia_semana * 24 * 60)) % 60<< "--";
				cout << "Hora de início : " << (condutores.at(i).getShifts().at(k).getEndTime() - (dia_semana * 24 * 60)) / 60 << " : " << (condutores.at(i).getShifts().at(k).getEndTime() - (dia_semana * 24 * 60)) % 60 << endl;
			}
			break;
		}
		if (i == condutores.size() - 1)
		{
			cout << "Não foi encontrado nenhum condutor com o número identificador inserido. \n";
			return;
		}

	}

	system("pause");
}


void Empresa::ver_inf_bus()
{
	unsigned int order, i, id, u;
	cout << "Introduza o número identificador da linha : "; cin >> id;
	cout << "Introduza o número do autocarro : "; cin >> order;
	for (i = 0; i < buses.size(); i++)
	{

		if (buses.at(i).getLineId() == id && buses.at(i).getBusOrderInLine() == order)
		{
			cout << "Linha " << buses.at(i).getLineId() << endl;
			cout << "Autocarro " << buses.at(i).getBusOrderInLine() << endl;//numero do autocarro
			for (u = 0; u < buses.at(i).getSchedule().size(); u++)
			{
				unsigned int h_inicio = buses.at(i).getSchedule().at(u).getStartTime();
				unsigned int h_fim = buses.at(i).getSchedule().at(u).getEndTime();
				unsigned int dia_semana = h_inicio / (60 * 24);

				switch (dia_semana)
				{
				case 0:
					cout << "Segunda-feira -> ";
					break;
				case 1:
					cout << "Terça-feira -> ";
					break;
				case 2:
					cout  << "Quarta-feira -> ";
					break;
				case 3:
					cout << "Quinta-feira -> ";
					break;
				case 4:
					cout << "Sexta-feira -> ";
					break;
				}
				cout << (h_inicio - (dia_semana * 24 * 60)) / 60 << " : " << (h_inicio - (dia_semana * 24 * 60)) % 60 << "  " << (h_fim - (dia_semana * 24 * 60)) / 60 << " : " << (h_fim - (dia_semana * 24 * 60)) % 60 << " --> ";
				if (buses.at(i).getSchedule().at(u).getDriverId() == 0)
				{
					cout << "Sem condutor atribuído ! \n";
				}
				else
				{
					cout << "Driver : " << buses.at(i).getSchedule().at(u).getDriverId() << endl;
				}
			}



		}
	}


	system("pause");

}

	





// INITIALISATION CODE GOES IN HERE


	//////////////
	// get methods
	//////////////

	unsigned int Driver::getId() const {
		return id;
	}

	string Driver::getName() const {
		return name;
	}

	unsigned int Driver::getShiftMaxDuration() const {
		return maxHours;
	}

	unsigned int Driver::getMaxWeekWorkingTime() const {
		return maxWeekWorkingTime;
	}

	unsigned int Driver::getMinRestTime() const {
		return minRestTime;
	}

	vector<Shift> Driver::getShifts() const {
		return shifts;
	}
	unsigned int Driver::getmax_week_hours() const {
		return max_week_hours;
	}

	///////////////5/7
	//// Set stuff
	///////////////5/7

	void Driver::setid(unsigned int id)
	{

		this->id = id;
	}


	void Driver::setmaxHours(unsigned int maxHours)
	{

		this->maxHours = maxHours;
	}

	void Driver::setmaxHours_week(unsigned int maxHours_week)
	{

		this->maxWeekWorkingTime = maxHours_week;
	}

	void Driver::setname(string name) 
	{
		this->name = name;
	}

	void Driver::setminrest(unsigned int minrest_time) 
	{
		this->minRestTime = minrest_time;
	}

	void Driver::set_shift(vector<Shift> turno)
	{
		shifts = turno;
	}
	void Driver::set_max_week_hours(unsigned int horas)
	{
		max_week_hours = horas;
	 }

