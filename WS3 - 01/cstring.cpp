#include <cstring>
#include "cstring.h"
#include <iostream>

int stored = w1::MAX;

namespace w1 {
	CString::CString(char* word) {
		if (word[0] == '\0') {
			c_string[0] = '\0';
		}
		else {
			strncpy(c_string, word, MAX);
			c_string[MAX] = '\0';
		}
	}
	
	
	std::ostream& CString::display(std::ostream& os) const {
		//std::cout << c_string << std::endl;
		os << c_string ;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, CString& c) {
		static int count = 0;
		//std::cout << count << ": " ;
		os << count << ": ";
		c.display(os);
		count++;
		return os;
	}
}