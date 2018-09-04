/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/

#include <iostream>
using namespace std;
// TODO: include the necessary headers
#include "Kingdom.h"
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...)
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
	void display(const Kingdom pKingdom[], int _count) {
		int total = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < _count; i++) {
			cout << i + 1 << ". " << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
			total += pKingdom[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}
}