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

#ifndef ERROR_STATE_H
#define ERROR_STATE_H

#include <iostream>

using namespace std;

namespace AMA {

	class ErrorState {

		char * addMsg;

	public:

		explicit ErrorState(const char * errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		virtual ~ErrorState();

		ErrorState& operator=(const ErrorState& em) = delete;
		void clear();
		bool isClear() const;
		void message(const char * str);
		ostream& write(ostream& ostr) const;
		const char * message() const;	

	};

	ostream& operator<<(ostream&, ErrorState&);
}

#endif