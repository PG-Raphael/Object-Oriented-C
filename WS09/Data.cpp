/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Data.h"

using namespace std;
namespace sict {


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationChange = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] /**/ << " is ";
		cout << fixed;
		cout.precision(2);
		cout << static_cast<double>(populationChange / 1E6) << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		auto CrimeFirst = violentCrime[0];
		auto CrimeLast = violentCrime[n - 1];
		const char *crimeResult = "";
		if (CrimeLast - CrimeFirst > 0)
		{
			crimeResult = "up";
		}
		else {
			crimeResult = "down";
		}
		cout << "Violent Crime trend is " << crimeResult << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double GTAnumber = average(grandTheftAuto, 5);
		GTAnumber = GTAnumber / 1E6;
		cout << "There are ";
		cout << fixed;
		cout.precision(2);
		cout << GTAnumber << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		int max_violentCrime = static_cast<int>(max(violentCrimeRate, 5));
		int min_violentCrime = static_cast<int>(min(violentCrimeRate, 5));
		cout << "The Minimum Violent Crime rate was " << min_violentCrime << endl;
		cout << "The Maximum Violent Crime rate was " << max_violentCrime << endl;
	}
}