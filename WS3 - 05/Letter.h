/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-10-09              *
*******************************/
#ifndef SICT_LETTER_H_
#define SICT_LETTER_H
#include <iostream>
#include <string>
namespace sict {
	//enumeration constants values
	enum Letter { aplus, a, bplus, b, cplus, c, dplus, d };
	//making an option to set the grade
	std::string str(Letter& lt) {
		switch (lt)
		{
		case aplus: return "A+";
			break;
		case a: return "A";
			break;
		case bplus: return "B+";
			break;
		case b: return "B";
			break;
		case cplus: return "C+";
			break;
		case c: return "C";
			break;
		case dplus: return "D+";
			break;
		case d: return "D";
			break;
				
		}
		return 0;
	}

}
#endif