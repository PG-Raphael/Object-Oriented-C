/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
namespace sict {

	SuperHero::SuperHero() : Hero() {
		c_bonus = 0;
		c_defend = 0;
	}
	SuperHero::SuperHero(const char name[], int health, int attack, int bonus, int defend) : Hero(name, health, attack) {
		if (bonus > 0 && defend > 0) {
			c_bonus = bonus;
			c_defend = defend;
		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::attackStrength() const {
		int tmp = 0;
		if (c_bonus <= 0 && c_defend <= 0) {
			tmp = Hero::attackStrength();
		}
		else {
			tmp = this->Hero::attackStrength() + c_bonus;
		}
		return tmp;
	}
	int SuperHero::defend() const {
		int tmp = 0;
		if (c_bonus <= 0 && c_defend <= 0) {
			tmp = 0;
		}
		else {
			tmp = this->c_defend;
		}
		return tmp;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int round = 0;
		SuperHero first1 = first;
		SuperHero second2 = second;
		const SuperHero *winner = nullptr;
		while (first1.isAlive() && second2.isAlive() && round < max_rounds) {
			round++;
			first1 -= second2.SuperHero::attackStrength() - first1.defend();
			second2 -= first1.SuperHero::attackStrength() - second2.defend();
		if (!first1.isAlive() || !second2.isAlive() || round == max_rounds) {
			if ((first1.isAlive() == second2.isAlive()) || (first1.isAlive() > second2.isAlive())) {
				winner = &first;
			}
			else if (first1.isAlive() < second2.isAlive()) {
				winner = &second;
			}
			else {
				std::cout << "No Winner" << endl;
			}
		}
	}

	cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;
	return *winner;
}
}