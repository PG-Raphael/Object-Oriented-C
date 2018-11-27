/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-10-09              *
*******************************/
#include "Grades.h"
using namespace std;

namespace sict {

	Grades::Grades(char* f)
	{
		//try block identifies a block of code for 
		//which particular exceptions will be activated. 
		//It's followed by one or more catch blocks.
		try
		{
			//stream class read from files
			ifstream fs(f);
			//it files opens do this
			if (fs.is_open())
			{
				int line = 0;
				string str;
				//count how many lines the file has
				while (getline(fs, str)) {
					line++;
				}
				//clear the buffer
				fs.clear();
				//find where to get the data from
				fs.seekg(0);

				count = line;
				//setting dynamically
				c_stID = new string[count];
				c_grade = new double[count];

				//copy the data to local variables
				for (int i = 0; i < count; i++) {
					fs >> c_stID[i];
					fs >> c_grade[i];
				}
				fs.close();
			}
			//A program throws an exception when a problem shows up.
			else throw "ERROR!!";
		}
		// program catches an exception with an exception handler at the place in a program where you want to handle the problem
		catch (const char* msg)
		{
			cerr << msg << endl;
			exit(0);
		}
	}
}