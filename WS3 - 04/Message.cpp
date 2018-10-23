/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#include <iomanip>
#include "Message.h"

namespace w4 {

	Message::Message() {
		tweet = "";
		name = "";
		reply = "";
	}// default constructor

	// retrieve a record from file object "in"
	// parse record and store its components in messageManager
	Message::Message(std::ifstream& in, char c) {
		std::string line = "";
		getline(in, line, c);

		auto cr = line.find('\r');
		if (cr != std::string::npos) {
			line.erase(cr);
		} // npos = no position, position not found

		size_t index = 0;
		size_t lastIndex = line.find_last_not_of(" \t");

		// process username
		while (line != "" && index < line.size() && line[index] != ' ') {
			name += line[index];
			index++;
		} // username

		// skip a space if present
		if (line[index] == ' ')
			index++;

		// process @reply if present
		if (line != "" && index < line.size() && line[index] == '@') {
			index++; // skip the '@'
			while (index < line.size() && line[index] != ' ') {
				reply += line[index];
				index++;
			}
		} // @reply

		// skip a space if present
		if (line[index] == ' ')
			index++;
		
		
		
		// process tweet
		while (line != "" && index < lastIndex + 1) {
			tweet += line[index];
			index++;			
		} // tweet
		
		
		

	} // overloaded constructor

	bool Message::empty() const {
		return name == "" || tweet == "" ? true : false;
	} 

	void Message::display(std::ostream& os) const {
		if (!empty()) {

			
			os << "Message" << std::endl;
			os << " " << std::setw(5) << std::setiosflags(std::ios::left) << "User" << " : " << name << std::endl;
			if (!reply.empty()) {
				os << " " << "Reply" << " : " << reply << std::endl;
			}
			os << " " << "Tweet" << " : " << tweet << ((char)13) << std::endl;
			os << std::endl;
		}
	} // display()


	// clear Message
	void Message::reset() {
		name.clear();
		reply.clear();
		tweet.clear();
	} // reset()

} // namespace w4