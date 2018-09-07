/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char c_name[32];
		char c_destination[32];
		int c_yearDeparture;
		int c_monthDeparture;
		int c_dayDeparture;
	public:
		//constructors
		Passenger();//defalut
		Passenger(const char name[], const char destination[]);//2 parameters
		Passenger(const char name[], const char destination[], const int year, const int month, const int day); //5 parameters
		bool isEmpty() const; // query
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif