#include "Shift.h"
#include"Empresa.h"

Shift::Shift(  unsigned int linha, unsigned int condutor, unsigned int autocarro, unsigned int inicio, unsigned int fim){
  
	busLineId = linha;
	driverId = condutor;
	busOrderNumber = autocarro;
	startTime = inicio;
	endTime = fim;

  

}




void Empresa::ver_turnos()
{
	unsigned int i, u ;

	unsigned int id, dia_semana, id_bus, dia, turno, driver_id;
	cout << "Insira o número identificador da linha : ";
	cin >> id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Introduza um número por favor ! \n";
		cin >> id;
	}

	for (i = 0; i < buses.size(); i++)
	{
		
		
		

		if (buses.at(i).getLineId() == id)
		{




			cout << "Linha " << buses.at(i).getLineId() << endl;
			cout << "Autocarro " << buses.at(i).getBusOrderInLine() << endl << "Turnos : \n";
			for (u = 0; u < buses.at(i).getSchedule().size(); u++)
			{
				unsigned int h_inicio = buses.at(i).getSchedule().at(u).getStartTime();
				unsigned int h_fim = buses.at(i).getSchedule().at(u).getEndTime();
				unsigned int dia_semana = h_inicio / (60 * 24);
				

			


				if (buses.at(i).getSchedule().at(u).getDriverId() == 0)
				{

					switch (dia_semana)
					{
					case 0:
						cout << "[" << u << "]" << "Segunda-feira -> ";
						break;
					case 1:
						cout << "[" << u << "]" << "Terça-feira -> ";
						break;
					case 2:
						cout << "[" << u << "]" << "Quarta-feira -> ";
						break;
					case 3:
						cout << "[" << u << "]" << "Quinta-feira -> ";
						break;
					case 4:
						cout << "[" << u << "]" << "Sexta-feira -> ";
						break;
					}
					cout<< (h_inicio - (dia_semana * 24 * 60)) / 60 << " : " << (h_inicio - (dia_semana * 24 * 60)) % 60 << "  " << (h_fim - (dia_semana * 24 * 60)) / 60 << " : " << (h_fim - (dia_semana * 24 * 60)) % 60 << endl;
				}



			}
			
			
			
		}
	
		
	}
	cout << "Insira o numero de um dos autocarros apresentados : "; cin >> id_bus;
	cout << "Selecione um dos dias da semana(segunda-feira=0,terça-feira=1,...,sexta-feira=4) : "; cin >> dia;
	cout << "Selecione um dos turnos apresentados(número apresentado entre []) : "; cin >> turno;
	cout << "Introduza o id do condutor a atribuir trabalho : "; cin >> driver_id;
	unsigned int j;
	for (j = 0; j < condutores.size(); j++)
	{
		if (condutores.at(j).getId() == driver_id)
		{
			vector<Shift> turnos = condutores.at(j).getShifts();

				turnos.push_back(buses.at(id_bus - 1).getSchedule().at(turno));
				
				condutores.at(j).set_shift(turnos);
				vector<Shift> turnos_1 = buses.at(id_bus - 1).getSchedule();
				turnos_1.at(turno).setDriverId(driver_id);
				buses.at(id_bus - 1 ).set_schedule(turnos_1);

			condutores.at(j).set_max_week_hours(condutores.at(j).getMaxWeekWorkingTime() * 60 - buses.at(id_bus - 1).get_duraçao()); //MUDAR
		}
	}
	system("pause");
}


// metodos get
unsigned int Shift::getBusLineId() const{
  return busLineId;
}

unsigned int Shift::getDriverId() const{
  return driverId;
}
unsigned int Shift::getBusOrderNumber() const{
  return busOrderNumber;
}

unsigned int Shift::getStartTime() const{
  return startTime;
}

unsigned int Shift::getEndTime() const{
  return endTime;
}

///////////////
// set methods
//////////////

void Shift::setBusLineId(unsigned int busLineId){
  this->busLineId = busLineId;
}

void Shift::setDriverId(unsigned int driverId){
  this->driverId = driverId;
}

void Shift::setBusOrderNumber(unsigned int busOrderNumber){
  this->busOrderNumber = busOrderNumber;
}

void Shift::setStartTime(unsigned int startTime){
  this->startTime = startTime;
}

void Shift::setEndTime(unsigned int endTime){
  this->endTime = endTime;
}
