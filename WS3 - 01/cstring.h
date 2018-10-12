#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>

namespace w1 {
	const int MAX = 3;
	class CString {
		 char c_string[MAX + 1];
	public:
		CString(char*);
		std::ostream& display(std::ostream &os) const;
	};
	std::ostream& operator<< (std::ostream& os, CString& c);
}
#endif // !CSTRING_H
