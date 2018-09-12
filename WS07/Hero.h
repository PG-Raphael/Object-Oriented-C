/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: OOP244SAB
----------------------------------------------------------------------*/
#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
	const int max_rounds = 100;
	class Hero {
		char c_name[41];
		int c_health;
		int c_atkPt;
	public:
		Hero();
		Hero(const char[], int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};
	
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif