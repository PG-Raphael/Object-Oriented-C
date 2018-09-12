/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;
namespace sict {

	Hero::Hero() {
		c_name[0] = '\0';
		c_health = 0;
		c_atkPt = 0;
	}
	Hero::Hero(const char name[], int health, int atk) {
		if (name != nullptr && health > 0 && atk > 0) {
			strncpy(c_name, name, 41 - 1);
			c_name[41 - 1] = '\0';
			c_health = health;
			c_atkPt = atk;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		
		if (attack > 0) {
			c_health -= attack;
			c_health = c_health > 0 ? c_health : 0;
		}
	}
	bool Hero::isAlive() const {
		return c_health > 0 ? true : false;
	}
	int Hero::attackStrength() const {
		return (c_name[0] == '\0') && (c_health == 0) && (c_atkPt == 0) ? 0 : c_atkPt;
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if ((hero.c_name[0] == '\0') && (hero.c_health == 0) && (hero.c_atkPt == 0)) {
			os << "No hero" << endl;
		}
		else {
			os << hero.c_name;
		}
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		int round = 0;
		Hero first1 = first;
		Hero second2 = second;
		const Hero *winner = nullptr;
		while (first1.isAlive() && second2.isAlive() && round < max_rounds) {
			round++;
			first1 -= second2.attackStrength();
			second2 -= first1.attackStrength();
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
		cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;

		return *winner;
	}
}