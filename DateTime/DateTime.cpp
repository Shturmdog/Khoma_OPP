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
	for (int i = 1; i < year; i++)
	{
		if (isLeapYear(i)) {
			globalDate += 366;
		}
		else {
			globalDate += 365;
		}
	}


	for (int i = 1; i < month; i++) {
		globalDate += daysInMonth(year, i);
	}

	globalDate += day;

	return globalDate;
}

bool DateTime::checkDate() {
	if (year < 1 || year > 3000)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth(year, month))
		return false;

	return true;
}

void DateTime::input() {
	cin >> day >> month >> year;
	if (!checkDate()) {
		cout << "Error: incorrect date" << endl;
	}
	else
	{
		cout << "Date: " << day << '.' << month << '.' << year;
	}

}