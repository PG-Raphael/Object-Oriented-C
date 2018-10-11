// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name   Seungmin Yun            Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;
namespace AMA {

	// number of days in month mon_ and year year_

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		c_check = errorCode;
	}
	//constructor
	Date::Date() {
		c_year = 0;
		c_month = 0;
		c_day = 0;
		c_check = NO_ERROR;
	}
	//checking error state
	bool Date::valid() {
		bool check = true;
		if (c_year < min_year || c_year > max_year) {
			c_check = YEAR_ERROR;
			check = false;
		}
		if ((check == true) && (c_month < 1 || c_month > 12)) {
			c_check = MON_ERROR;
			check = false;
		}
		if ((check == true) && (c_day < 1 || c_day > mdays(c_month, c_year))) {
			c_check = DAY_ERROR;
			check = false;
		}
		return check;
	}
	//another constructor
	Date::Date(int year, int month, int day) {
		if (year > 0 && (month > 0 && month < 13) && (day > 0 && day <= mdays(month, year))) {
			c_year = year;
			c_month = month;
			c_day = day;
		}
		if (valid()) {
			c_check = NO_ERROR;
		}
		else {
			*this = Date();
		}
	}

	bool Date::isEmpty() const {
		return (c_year == 0 && c_month && 0 && c_day == 0) ? true : false;
	}

	int Date::comparator() const {
		return c_year * 372 + c_month * 13 + c_day;
	}

	bool Date::operator==(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() == rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	bool Date::operator!=(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() != rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	bool Date::operator<(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() < rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	bool Date::operator>(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() > rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	bool Date::operator<=(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() <= rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	bool Date::operator>=(const Date& rhs) const {
		bool check;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (comparator() >= rhs.comparator()) {
				check = true;
			}
			else {
				check = false;
			}
		}
		return check;
	}

	int Date::errCode() const {
		return c_check;
	}

	bool Date::bad() const {
		return c_check != NO_ERROR ? true : false;
	}

	std::istream& Date::read(std::istream& istr) {
		char slash;
		istr.clear();
		istr >> c_year >> slash >> c_month >> slash >> c_day;
		if (istr.fail()) {
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (min_year > c_year || max_year < c_year) {
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > c_month || 12 < c_month) {
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (c_day > mdays(c_month, c_year)) {
			*this = Date();
			errCode(DAY_ERROR);
		}
		else {
			istr.clear();
		}
		istr.clear();
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << c_year << '/' << setw(2) << setfill('0') << c_month << '/' << setw(2) << setfill('0') << c_day;
		return ostr;
	}

	std::istream& operator>>(std::istream& is, Date& d) {
		return d.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const Date& d) {
		return d.write(os);
	}
}
