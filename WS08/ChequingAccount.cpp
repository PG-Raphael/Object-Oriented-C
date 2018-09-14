// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double bal, double tranFee, double monFee) : Account(bal) {
		c_transaction = tranFee > 0 ? tranFee : 0;
		c_Mfee = monFee > 0 ? monFee : 0;
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double money) {
		bool valid = false;
		if (money > 0 && (balance() + money) - c_transaction > 0) {
			double check = money - c_transaction;
			Account::credit(check);
			valid = true;
		}
		return valid;
	}




	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double money) {
		bool valid = false;
		if (money > 0 && (balance() + money) - c_transaction > 0) {
			double check = money + c_transaction;
			Account::debit(check);
			valid = true;
		}
		return valid;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd()
	{
		Account::debit(c_transaction + c_Mfee);
	}



	// display inserts account information into ostream os
	//

	void ChequingAccount::display(std::ostream& out) const
	{
		out << fixed << setprecision(2);
		out << "Account type: Chequing" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << c_transaction << endl;
		out << "Monthly Fee: " << c_Mfee << endl;
	}



}