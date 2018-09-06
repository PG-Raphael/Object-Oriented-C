/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"
//declare using namespace std and sict to refer
using namespace std;
using namespace sict;

//set funcion, if sin is correct value value goes specific members that i chose.
void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

	if ((sin > min_sin) && (sin < max_sin)) {
		int i;
		int remain = 0;
		int raise = 0;
		int check = 0;
		int total = 0;
		remain += sin % 10;//ex)193456787 --> 7
		int c_sin1 = sin / 10;// ex 193456787 --> 19345678.7 -- > 19345678
		int c_sin2 = sin / 100; // ex 193456787 --> 1934567.87 -- > 1934567

		for (i = 0; i < 4; i++) {
			int addEachNum = 2 * (c_sin1 % 10); // ex 19345678 -- > 2 * 8
			if (addEachNum >= 10) {
				total += addEachNum % 10; // addEachNum = 16 --> 0 + 6, 6 + 1 --> check = 7
				total += addEachNum / 10;
			}
			else {
				total += addEachNum;
			}
			c_sin1 /= 100; // ex 19345678 --> 193456
		}
		for (i = 0; i < 4; i++) {
			total += (c_sin2 % 10); //27 + 7 = 34
			c_sin2 /= 100; // ex 1934567 --> 19345
		}
		raise = raising(total);
		check = raise - total;

		if (check == remain) {
			//strncpy --> copy the string right to left and specify number of elements	
			strncpy(c_familyName, familyName, max_name_length);
			//if member's names are same u can use this->name -->strncpy(this->familyName, familyName, max_name_length);
			strncpy(c_givenName, givenName, max_name_length);
			c_sin = sin;
			c_years = 0;
		}

		else {
			//making empty.
			strncpy(c_familyName, "", max_name_length);
			strncpy(c_givenName, "", max_name_length);
			c_sin = 0;
			c_years = 0;
		}
	}


}
//bool type function 
bool CRA_Account::isEmpty() const {
	if ((c_sin == 0)  || (c_familyName[0] == '\0') || (c_givenName[0] == '\0'))
	{
		return true;
	}
	else {
		return false;
	}
}

//if condition is true, display outputs
void CRA_Account::display() const {
	if (c_sin != 0) {
		cout << "Family Name: " << c_familyName << endl;
		cout << "Given Name : " << c_givenName << endl;
		cout << "CRA Account: " << c_sin << endl;
		for (int i = 0; i < max_yrs; i++) {
			//This makes cout display floating point values in fixed point notation.
			cout.setf(ios::fixed);
			//print out up to decimal 2 points
			cout.precision(2);
			if (c_balanceOwe[i] > 2) {
				cout << "Year (" << c_taxYrs[i] << ") balance owing: " << fabs(c_balanceOwe[i]) << endl;
			}
			else if (c_balanceOwe[i] < -2) {
				cout << "Year (" << c_taxYrs[i] << ") refund due: " << fabs(c_balanceOwe[i]) << endl;
			}
			else
				cout << "Year (" << c_taxYrs[i] << ") No balance owing or refund due!" << endl;
		}
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}
void CRA_Account::set(int year, double balance) {
	if ((c_sin != 0) && (c_sin > min_sin) && (c_sin < max_sin)) {
		if (c_years < max_yrs) {
			c_taxYrs[c_years] = year;
			c_balanceOwe[c_years] = balance;
			c_years++;
		}
	}
}
int CRA_Account::raising(int num) {
	int tmp = 0;
	tmp = num / 10;
	return (tmp * 10) + 10;
}