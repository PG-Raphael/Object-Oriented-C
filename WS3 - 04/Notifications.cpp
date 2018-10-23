/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#include <iostream>
#include "Notifications.h"

namespace w4 {
	Notifications::Notifications() {
		count = 0;
		c_MsgManager[0] = {};
	}
	Notifications::Notifications(const Notifications& rhs) {
		if (this != NULL) {
			*this = rhs;
		}
	} // copy constructor

	Notifications& Notifications::operator=(const Notifications& rhs) {
		if (this != &rhs) {
			if (rhs.c_MsgManager) {
				count = rhs.count;
				for (size_t i = 0; i < count; i++) {
					c_MsgManager[i] = rhs.c_MsgManager[i];
				}
			}
		}

		return *this;
	} // copy assignment operator

	Notifications::Notifications(Notifications&& rhs) {
		*this = std::move(rhs);
	} // move constructor

	Notifications&& Notifications::operator=(Notifications&& rhs) {
		if (this != &rhs) {			
			for (size_t i = 0; i < count; i++) {
				c_MsgManager[i].reset();
			}
			count = 0;

			// move rhs to *this
			count = rhs.count;
			for (size_t i = 0; i < count; i++) {
				c_MsgManager[i] = rhs.c_MsgManager[i];
				rhs.c_MsgManager[i].reset();	// turn rhs into zombie
			}
			rhs.count = 0;
		}

		return std::move(*this);
		
	} // move assignment operator

	Notifications::~Notifications() {
		count = 0;
		c_MsgManager[0].reset();
	} // destructor

	// add msg to the set
	void Notifications::operator+=(const Message& msg) {
		if (count < MAX_MESSAGE) {
			c_MsgManager[count] = std::move(msg);
			count++;
		}
		else {
			std::cerr << __FILE__ << ":" << __LINE__
				<< " compiled on " << __DATE__ << " at " << __TIME__
				<< " messageTable FULL!" << std::endl
				<< "increase MESSAGE_MAX and recompile" << std::endl;
			exit(99);
		}
	} // operator+=

	// inserts the Message objects to the os output stream
	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0; i < count; i++) {
			c_MsgManager[i].display(os);
		}
	} // display()

} // namespace w4
