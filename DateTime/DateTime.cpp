#include <iostream>
#include "DateTime.h"
using namespace std;

DateTime::DateTime() : year(1997), month(12), day(6) {}

bool DateTime::isLeapYear(int y) const
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateTime::daysInMonth(int y, int m) const
{
	static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2 && isLeapYear(y))
		return 29;
	return days[m - 1];
}

int DateTime::DateEaster() {
	int globalDate = 0;
	for (int i = 0; i < year; i++) {
		if (isLeapYear(i)) {
			globalDate += 366;
		}
		else {
			globalDate += 355;
		}
	}

	return globalDate;
}

