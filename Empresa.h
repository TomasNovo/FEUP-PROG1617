#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Condutor.h"
#include "Bus.h"


using namespace std;

class Empresa{
 private:
  string nome;
  string fichCondutores;
  string fichLinhas;
  vector<Driver> condutores;
  vector<Line> linhas;
  vector<Bus> buses;
 public:
	 Empresa(string nome, string fichCondutores, string fichLinhas);
	 void pesq_driv();//PESQUISA DO CONDUTOR
	 void criar_driv();////criar driver
	 void alterar_driv(unsigned int );////alterar driver
	 void remover_driv(unsigned int );////remover driver
	 void menu_conds();//menu principal de condutores
	 void ler_driv();//listar tds os condutores(mais tarde a modificar para listar tds o condutores disponíveis)
	 void menu_linhas();
	 void PesquisaParagem();
	 unsigned int number_buses(unsigned int);
	 void ver_turnos();
	 void ver_inf_driv();
	 void ver_inf_bus();
	 void hor_linhas();
	 void hor_paragem();
	 
  // metodos get
  string getNome() const;
  // metodos set
  // outros metodos
  void distribuiServico(); // funcao que implementa a afectacao de servico
};


