/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H
#include <iostream>
#include "Message.h"

namespace w4 {

	const size_t MAX_MESSAGE = 10;

	class Notifications {
		Message c_MsgManager[MAX_MESSAGE];
		size_t count = 0;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	}; 

}
#endif