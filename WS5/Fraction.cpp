/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
// TODO: insert header files
#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		numerator = -1;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numer, int denomi)
	{
		if (numer >= 0 && denomi > 0)
		{
			numerator = numer;
			denominator = denomi;
			reduce();
		}
		else {
			numerator = 0;
			denominator = 0;
		}
	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		return (numerator > denominator) ? numerator : denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		return (numerator > denominator) ? denominator : numerator;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int tmpnum = gcd();
		numerator /= tmpnum;
		denominator /= tmpnum;
	}
	// TODO: implement the display query
	void Fraction::display() const
	{
		const bool empty = isEmpty();
		if (empty)
		{
			cout << "no fraction stored";
		}
		else {
			if (numerator%denominator == 0)
			{
				cout << numerator / denominator;
			}
			else {
				cout << numerator << "/" << denominator;

			}
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		return (numerator == 0 || denominator == 0) ? true : false;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result = *this;
		if (result.isEmpty() && rhs.isEmpty()) {
			result.numerator = 0;
			result.denominator = 0;
		}
		else {
			result += rhs;
		}
		return result;
	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction total;
		if (isEmpty() && rhs.isEmpty()) {
			total.denominator = 0;
			total.numerator = 0;
		}
		else {
			total.denominator = denominator * rhs.denominator;
			total.numerator = numerator * rhs.numerator;
		}
		return total;
	}
	bool Fraction::operator==(const Fraction& rhs) const {
		bool check;
		if (isEmpty() && rhs.isEmpty()) {
			check = false;
		}
		if (numerator == rhs.numerator && denominator == rhs.denominator) {
			check = true;
		}
		return check;
	}
	bool Fraction::operator!=(const Fraction& rhs) const {
		bool check;
		if (isEmpty() && rhs.isEmpty()) {
			check = false;
		}
		if (numerator != rhs.numerator && denominator != rhs.denominator) {
			check = true;
		}
		return check;
	}
	Fraction Fraction::operator+=(const Fraction& rhs) {
		Fraction& tmp = *this;
		if (tmp.isEmpty() && rhs.isEmpty()) {
			tmp.denominator = 0;
			tmp.numerator = 0;
		}
		else {
			tmp.numerator = (numerator * rhs.denominator) + (rhs.numerator*denominator);
			tmp.denominator = denominator * rhs.denominator;
		}
		return tmp;
	}
}



