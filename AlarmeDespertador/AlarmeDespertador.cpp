/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1103

#######################################

Exemplo de entrada:
1 5 3 5
23 59 0 34
21 33 21 10
0 0 0 0

######################################

Exemplo de saída:
120
35
1417

*/

#include "pch.h"
#include <iostream>

using namespace std;

class HourMinute
{
	int hours, minutes;

	public :HourMinute(int hours, int minutes)
	{
		this->hours = hours;
		this->minutes = minutes;
	}

	// Returns the difference (in minutes) between the two HourMinute objects
	int operator -(HourMinute &h)
	{
		int resMinutes, resHours, finalResult;

		resMinutes = this->minutes - h.minutes;
		resHours = this->hours - h.hours;
		
		if (resMinutes < 0)
		{
			resMinutes += 60;
			--resHours;
		}

		if (resHours < 0)
			resHours += 24;
		
		return (resHours * 60) + resMinutes; 
	}
};

int main()
{
	int h1, m1, h2, m2;

	while (cin >> h1 >> m1 >> h2 >> m2)
	{
		if (h1 == 0 &&
			m1 == 0 &&
			h2 == 0 &&
			m2 == 0)
			break;

		HourMinute hm1 = HourMinute(h1, m1);
		HourMinute hm2 = HourMinute(h2, m2);

		int result = hm2 - hm1;

		cout << result << endl;
	}
}