#include <iostream>
#include "cstring.h"
#include "process.h"

void process(char* word, std::ostream& os) {
	w1::CString s(word);
	os << s << std::endl;
}