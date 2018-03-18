#include <iostream>
#include "Condutor.h"
#include "Empresa.h"


int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	string nome_empresa, nomefich_driv, nomefich_lines;

	cout << "Insira o nome da empresa : "; getline(cin,nome_empresa);
	cout << "Insira o nome do ficheiro de condutores : "; getline(cin,nomefich_driv);
	cout << "Insira o nome do ficheio de linhas : "; getline(cin,nomefich_lines);
	Empresa Company("semprearolar", "drivers.txt", "linhas.txt");
	char option2;
	option2 = '420';
	while (option2 != '3')
	{
		system("cls");
		cout << "Selecione a opção : \n" << "1-Gestão de linhas \n" << "2-Gestão de condutores \n" << "3-Sair \n";
		cin.clear(); cin >> option2; cin.ignore(10000, '\n');
		int option = option2 - '0';



		switch (option) {
		case 1:
			Company.menu_linhas();
			break;

		case 2:
			Company.menu_conds();
			break;
		}
	
	}
	//IMPLEMENTAR A ESCRITA NOS FICHEIROS
	return 0;
}
	