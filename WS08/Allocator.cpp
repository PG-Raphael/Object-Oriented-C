/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include "ChequingAccount.h"
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double intRate = 0.05;
	const double transactionfee = 0.5;
	const double monthlyfee = 2;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double bal) {
		
		if (type[0] == 's' || type[0] == 'S') {
			SavingsAccount* CreateAccount = new SavingsAccount(bal, intRate);
			return CreateAccount;
		}
		else if (type[0] == 'c' || type[0] == 'C') {
			ChequingAccount* CreateAccount = new ChequingAccount(bal, transactionfee, monthlyfee);
			return CreateAccount;
		}
		else {
			return nullptr;
		}
	}
}