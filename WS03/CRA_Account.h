/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

//using namespace as sict
namespace sict {
	//const values to set range
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	//declare calss
	class CRA_Account {
		//private members
		char c_familyName[max_name_length + 1];
		char c_givenName[max_name_length + 1];
		int c_sin;
		int c_years;
		int c_taxYrs[max_yrs];
		double c_balanceOwe[max_yrs];
		//public memeber functions to access private members
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
		int raising(int num);
	};

};
#endif