/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;


namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n) {
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] > max)
				max = data[i];
		}
		return max;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n)
	{
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] < min)
				min = data[i];
		}
		return min;
	}
        
	// sum returns the sum of n items in data
	//    
	template <typename T>
	T sum(const T* data, int n)
	{
		T sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += data[i];
		}
		return sum;
	}
	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n)
	{		
		int average = 0;
		average = sum(data, n) / n;
		return average;
	}
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(istream& input, T* data, int n)
	{
		bool valid = true;
		
		for (int i = 0; i < n; i++)
		{
			input.ignore();
			input >> data[i];
			if (input.fail())
				valid = false;
		}
		return valid;
	}
	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, T* data, int n)
	{
		cout.width(20);
		cout << name;
		for (int i = 0; i < n; i++)
		{
			cout.width(COLUMN_WIDTH);
			cout << data[i];
		}
		cout << std::endl;
	}
	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();
		if (ok)
		{
			input.get(rowname, 2000, ',');
			if (std::strcmp(rowname, name) != 0)
			{
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}
		if (ok)
			ok = read(input, data, n);
		input.ignore(2000, '\n');
		return ok;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

