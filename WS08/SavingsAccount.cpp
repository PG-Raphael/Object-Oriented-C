/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;
using namespace sict;
SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal) {
	c_rate = 0;
	if (rate > 0)
		c_rate = rate;
}
void SavingsAccount::monthEnd() {
	credit(balance() * c_rate);
}
void  SavingsAccount::display(std::ostream& os) const
{
	os << fixed << setprecision(2);
	os << "Account type: Savings" << endl;
	os << "Balance: $" << balance() << endl;
	os << "Interest Rate (%): " << c_rate * 100 << endl;
}


