/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero :public Hero {
		int c_bonus;
		int c_defend;
	public:
		SuperHero();
		SuperHero(const char[], int, int , int , int );
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif