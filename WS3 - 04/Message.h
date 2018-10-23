/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#pragma once
#include <iostream>

#include <iostream>
#include <fstream>
#include <string>

namespace w4 {

	class Message {
		std::string name;
		std::string reply;
		std::string tweet;
	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream& os) const;
		void reset();
	
	}; // class Message

} // namespace w4