/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-10-09              *
*******************************/
#ifndef SICT_GRADES_H_
#define SICT_GRADES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

namespace sict {
	class Grades {
		string* c_stID;
		double* c_grade;
		//to count index size
		int count;

	public:
		//set the default value
		Grades() : c_stID(nullptr), c_grade(nullptr), count(0) {}
		Grades(char*);
		//template for the display
		template<typename T>
		void displayGrades(std::ostream& os, T t) const {
			for (size_t i = 0; i < count - 1; i++) {
				os << "   " << c_stID[i] << " " << fixed << setprecision(2) << c_grade[i] << " " << t(c_grade[i]);
				//the maximum size of grade is 1
				if (t(c_grade[i]).size() == 1)
					os << "   " << endl;
				else
					os << "  " << endl;
			}
			
		}
		//prohibit copy and move
		Grades(const Grades& copy) = delete;
		Grades(Grades&& move) = delete;
		Grades& operator=(const Grades& copy) = delete;
		Grades&& operator=(Grades&& move) = delete;
	};
}
#endif