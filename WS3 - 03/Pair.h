/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-09-29              *
*******************************/
#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {
	A c_key;
	B c_value;
public:
	Pair() : c_key{ 0 }, c_value{ 0 } {}
	Pair(const A& a, const B& b) {
		c_key = a;
		c_value = b;
	}

	const A& getKey() const {
		return c_key;
	}

	const B& getValue() const {
		return c_value;
	}
};
#endif // !PAIR_H

