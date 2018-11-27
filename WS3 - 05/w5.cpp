// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	try {
		//call the function
	sict::Grades grades(argv[1]);
	//lambda expression to set the value based on enumeration constants values
	auto letter = [](double grade)->std::string
	{
		string strl;
		Letter lt;
		if (grade >= 90) lt = aplus;
		else if (grade >= 80) lt = a;
		else if (grade >= 75) lt = bplus;
		else if (grade >= 70) lt = b;
		else if (grade >= 65) lt = cplus;
		else if (grade >= 60) lt = c;
		else if (grade >= 55) lt = dplus;
		else if (grade >= 50) lt = d;
		/*else lt = f;*/
		strl = str(lt);
		return strl;
	};

	
		grades.displayGrades(std::cout, letter);
	}
	catch (const char* msg) {
		// report the error message
		std::cerr << msg << endl;
	}
	return 0;
}