#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include "Shift.h"


using namespace std;


class Driver{
 private:
  unsigned int id;
  string name;
  unsigned int maxHours;        // maximum duration of a shift
  unsigned int maxWeekWorkingTime;
  unsigned int max_week_hours;  // maximum number of hours of work in a week
  unsigned int minRestTime;     // minimum number of rest hours between shifts
  vector<Shift> shifts;         // assigned shifts
 public:
  Driver(string textLine);
  Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime);
  // get methods
  unsigned int getId() const;
  string getName() const;
  unsigned int getShiftMaxDuration() const;
  unsigned int getMaxWeekWorkingTime() const;
  unsigned int getmax_week_hours() const;
  unsigned int getMinRestTime() const;
  vector<Shift> getShifts() const;
  
  

  void setid (unsigned int);
  void setmaxHours(unsigned int);
  void setmaxHours_week(unsigned int);
  void setname(string);
  void setminrest(unsigned int);
  void set_shift(vector<Shift> );
  void set_max_week_hours(unsigned int);

  // outher methods

};

