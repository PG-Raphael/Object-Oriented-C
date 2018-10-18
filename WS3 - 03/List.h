/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#ifndef LIST_H
#define LIST_H

template <typename T, int N>
class List {
	T c_arr[N];
	int c_size;
public:
	List() : c_size{ 0 } {}

	size_t size() const { return c_size; }

	const T& operator[](int index) const {
			return c_arr[index];
			}

	void operator+=(const T& a) {
		if (size() < N) {
			c_arr[size()] = a;
				c_size++;
			}
		}
	};

#endif



