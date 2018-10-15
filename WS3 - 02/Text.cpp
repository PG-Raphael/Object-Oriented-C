/**********************************
| Subject        : Workshop 2     |
| Name           : Seungmin Yun   |
| Student number : 010820132      |
**********************************/
#include "Text.h"

using namespace w3;

Text::Text()
{
	// set the object to a safe empty state
	c_string = nullptr;
	count = 0;
}

// PARAM fileName: name of text file that contains records to be stored
Text::Text(const string fileName) : count(0)
{
	ifstream is(fileName);

	// check if file exists
	if (is.is_open())
	{
		int tmpcount = 0;
		string line;

		// get count of fields
		do
		{
			getline(is, line, '\n');
			tmpcount++;
		} while (!is.fail());

		// go back to beginning of file
		is.clear();
		is.seekg(0, ios::beg);

		// allocate memory for fields
		c_string = new string[tmpcount];

		// read into the array
		for (int i = 0; !is.fail(); i++)
			getline(is, c_string[i], '\n');

		// set field count
		count = tmpcount;

		// close file
		is.close();
	}
	else
		Text();	// assume a safe empty state instead
}

// copy constructor
// PARAM other: object being copied from
Text::Text(const Text& t)
{
	count = 0;
	c_string = '\0';
	*this = t;
}

// copy operator=
// PARAM other: object being copied from
Text& Text::operator=(const Text& t)
{
	if (this != &t)
	{
		if (c_string)
		{
			delete[] c_string;
			c_string = '\0';
			count = 0;
		}

		if (t.c_string)
		{
			count = t.count;
			c_string = new string[count];

			for (size_t i = 0; i < count; i++)
				c_string[i] = t.c_string[i];
		}
	}

	return *this;
}

// move constructor
// PARAM other: object being moved from
Text::Text(Text&& t)
{
	count = 0;
	c_string = '\0';
	*this = move(t);
}

// move operator=
// PARAM other: object being moved from
Text&& Text::operator=(Text&& t)
{
	if (this != &t)
	{
		if (c_string)
		{
			delete[] c_string;
			c_string = '\0';
			count = 0;
		}
		count = t.count;
		c_string = t.c_string;
		
		Text(t);	
	}
	return move(*this);
}

// destructor
Text::~Text()
{
	// take care of dynamic array for strings
	delete[] c_string;
	c_string = nullptr;
}

// returns the number of records of text data
size_t Text::size() const
{
	return count;
}