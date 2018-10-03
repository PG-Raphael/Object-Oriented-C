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
// Name     Seungmin Yun          Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR   0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

	class Date {

		int c_year;
		int c_month;
		int c_day;
		int c_check;

		int comparator() const;
		int mdays(int, int)const;
		void errCode(int errorCode);

	public:
		Date();
		Date(int, int, int);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		bool valid();
		bool isEmpty() const;
		int errCode() const;
		bool bad() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}
#endif

