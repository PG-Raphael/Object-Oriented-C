/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include "Account.h"

namespace sict {
	double Account::balance() const {
		return c_balance;
	}
	Account::Account(double balance) {
		if (balance > 0)
			c_balance = balance;
		else
			c_balance = 0.0;
	}
	bool Account::credit(double money) {
		bool valid = false;
		if (money > 0) {
			c_balance += money;
			valid = true;
		}
		return valid;
	}
	bool Account::debit(double money) {
		bool valid = false;
		if (money > 0) {
			c_balance -= money;
			valid = true;
		}
		return valid;
	}
}