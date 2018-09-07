/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
// TODO: continue your namespace here
using namespace std;
using namespace sict;
// TODO: implement the default constructor here
Passenger::Passenger()
{
	c_name[0] = '\0';
	c_destination[0] = '\0';
	c_yearDeparture = 0;
	c_monthDeparture = 0;
	c_dayDeparture = 0;
}

// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char name[], const char destination[])
{
	if ((name == '\0') || (destination == '\0'))
	{
		c_name[0] = '\0';
		c_destination[0] = '\0';
		c_yearDeparture = 0;
		c_monthDeparture = 0;
		c_dayDeparture = 0;
	}
	else {
		strncpy(c_name, name, 32-1);
		c_name[32 - 1] = '\0';
		strncpy(c_destination, destination, 32-1);
		c_destination[32 - 1] = '\0';
		c_yearDeparture = 2017;
		c_monthDeparture = 7;
		c_dayDeparture = 1;
	}
}
// TODO: implement isEmpty query here
bool Passenger::isEmpty() const
{
	return (c_name[0] == '\0' || c_destination[0] == '\0') ? true : false;
}
// TODO: implement display query here
void Passenger::display() const
{
	if ((isEmpty() == 1) || (c_yearDeparture != 0) || (c_monthDeparture != 0) || (c_dayDeparture != 0))
	{
		cout << c_name << " - " << c_destination <<
			" on " << c_yearDeparture << "/";
		if (c_monthDeparture < 10)
		{
			cout << "0";
		}
		cout << c_monthDeparture << "/";
		if (c_dayDeparture < 10)
		{
			cout << "0";
		}
		cout << c_dayDeparture << endl;
	}
	else {
		cout << "No passenger!" << endl;
	}
}
Passenger::Passenger(const char name[], const char destination[], const int year, const int month, const int day)
{
	if ((name == '\0') || (destination == '\0') ||
		(year < 2017) || (year > 2020) || (month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		c_name[0] = '\0';
		c_destination[0] = '\0';
		c_yearDeparture = 0;
		c_monthDeparture = 0;
		c_dayDeparture = 0;
	}
	else {
		strncpy(c_name, name, 32 - 1);
		c_name[32 - 1] = '\0';
		strncpy(c_destination, destination, 32 - 1);
		c_destination[32 - 1] = '\0';
		c_yearDeparture = year;
		c_monthDeparture = month;
		c_dayDeparture = day;
	}
}

const char* Passenger::name() const
{
	return this->c_name;
}

bool Passenger::canTravelWith(const Passenger& aPassenger) const
{
	return ((c_yearDeparture == aPassenger.c_yearDeparture) && (c_monthDeparture == aPassenger.c_monthDeparture)
		&& (c_dayDeparture == aPassenger.c_dayDeparture)) ? true : false;
}
