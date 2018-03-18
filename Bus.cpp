#include "Bus.h"



Bus::Bus(unsigned int id, unsigned int id_linha, unsigned int duracao, unsigned int number_bus, unsigned int freq) {

	orderInLine = id;
	lineId = id_linha;
	dura�ao = duracao;

	unsigned int h_inicio;
	unsigned int h_fim;

	for (int dia = 0; dia < 5; dia++)
	{
		h_inicio = 480 + ((id - 1) * freq) + (dia * 24 * 60);

		while (h_inicio < (1260 + (dia * 24 * 60)))
		{
			h_fim = h_inicio + duracao;

			Shift turno(id_linha, 0, id, h_inicio, h_fim); //Shifts com id do condutor a 0 n�o t�m condutor atribuido

			schedule.push_back(turno);

			h_inicio += number_bus * freq;
		}

	}
}
////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus:: getBusOrderInLine() const{
  return orderInLine;
}

unsigned int Bus::getDriverId() const{
  return driverId;
}

unsigned int Bus::getLineId() const{
  return lineId;
}
unsigned int Bus::get_dura�ao() const {
	return dura�ao;
}

vector<Shift> Bus::getSchedule() const{
  return schedule;
}


//////////////////////////////
// metodos set
/////////////////////////////

void Bus::set_schedule(vector <Shift> turnos) {
	schedule = turnos;
}



////////////////////////////
// outher methods
///////////////////////////
