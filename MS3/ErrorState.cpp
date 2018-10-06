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
#include <cstring>
#include "ErrorState.h"
using namespace std;
namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		addMsg = nullptr;
		if (errorMessage != nullptr)
		{
			message(errorMessage);
		}
	}
	ErrorState::~ErrorState() {
		clear();
	}
	void ErrorState::clear() {
		if (addMsg != nullptr) {
			delete[] addMsg;
		}
		addMsg = nullptr;
	}
	bool ErrorState::isClear() const {
		return addMsg == nullptr;
	}
	void ErrorState::message(const char* str) {
		clear();
		addMsg = new char[strlen(str) + 1];
		strcpy(addMsg, str);

	}
	const char* ErrorState::message()const {
		return addMsg;
	}
	ostream& ErrorState::write(ostream& os) const {

		if (addMsg != nullptr) {

			os << addMsg;
		}

		return os;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorState& err) {
		err.write(os);
		return os;
	}

}