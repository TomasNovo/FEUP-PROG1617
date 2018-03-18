#pragma once

#include <iostream>
#include <vector>

#include "Shift.h"


using namespace std;

class Bus{
 private:
  unsigned int orderInLine;
  unsigned int driverId;
  unsigned int lineId;
  unsigned int dura�ao;
  vector<Shift> schedule;
 public:
	 Bus(unsigned int id, unsigned int id_linha, unsigned int dura�ao, unsigned int number_bus, unsigned int freq);
  // get methods
  unsigned int getBusOrderInLine() const;
  unsigned int getDriverId() const;
  unsigned int getLineId() const;
  unsigned int get_dura�ao() const;
  vector<Shift> getSchedule() const;
  // set methods

  void set_schedule(vector<Shift>);

  // other methods

};
