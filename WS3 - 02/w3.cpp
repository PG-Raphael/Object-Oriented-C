// Workshop 3 - Copy and Move Semantics
// w3.cpp
//Author:  Dr. Elliott Coleshill
//Date:    2018-08-22

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <ctime>
#include "Text.h"
#define TIME(start, end) double((end) - (start)) / CLOCKS_PER_SEC

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab2Output.txt");

	if (argc == 1) {
		ofs << argv[0] << ": missing file operand\n";
		return 1;
	}
	else if (argc != 2) {
		ofs << argv[0] << ": too many arguments\n";
		return 2;
	}
	std::clock_t cs, ce;
	{
		ofs << std::fixed << std::setprecision(3);
		cs = std::clock();
		w3::Text a;
		ce = std::clock();
		ofs << "Constructor      " << TIME(cs, ce) << " seconds";
		std::cout << "Constructor      " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - a.size = " << a.size() << std::endl;

		cs = std::clock();
		w3::Text b(argv[1]);
		ce = std::clock();
		ofs << "Constructor      " << TIME(cs, ce) << " seconds";
		std::cout << "Constructor      " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - b.size = " << b.size() << std::endl;
		std::cout << " - b.size = " << b.size() << std::endl;

		cs = std::clock();
		a = b;
		ce = std::clock();
		ofs << "Copy Assignment  " << TIME(cs, ce) << " seconds";
		std::cout << "Copy Assignment  " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - a.size = " << a.size() << std::endl;

		cs = std::clock();
		a = std::move(b);
		ce = std::clock();
		ofs << "Move Assignment  " << TIME(cs, ce) << " seconds";
		std::cout << "Move Assignment  " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - a.size = " << a.size() << std::endl;

		cs = std::clock();
		w3::Text c = a;
		ce = std::clock();
		ofs << "Copy Constructor " << TIME(cs, ce) << " seconds";
		std::cout << "Copy Constructor " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - c.size = " << c.size() << std::endl;

		cs = std::clock();
		w3::Text d = std::move(a);
		ce = std::clock();
		ofs << "Move Constructor " << TIME(cs, ce) << " seconds";
		std::cout << "Move Constructor " << TIME(cs, ce) << " seconds" << std::endl;
		ofs << " - d.size = " << d.size() << std::endl;

		cs = std::clock();
	}
	ce = std::clock();
	ofs << "Destructor       " << TIME(cs, ce) << " seconds\n";
	std::cout << "Destructor       " << TIME(cs, ce) << " seconds\n" << std::endl;

	std::cout << "Check the Lab2Output.txt file for full results" << std::endl;

	ofs.close();
}