#ifndef W3_TEXT_H__
#define W3_TEXT_H__

/**********************************
| Subject        : Workshop 2     |
| Name           : Seungmin Yun   |
| Student number : 010820132      |
| |
**********************************/
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace w3
{
	class Text
	{
		size_t count;
		string* c_string;

	public:
		Text();
		Text(const string );

		// copy constructor and operator
		Text(const Text& );
		Text& operator=(const Text& );

		// move constructor and operator
		Text(Text&& );
		Text&& operator=(Text&& );

		~Text();

		// returns number of records of text data
		size_t size() const;
	};
}

#endif