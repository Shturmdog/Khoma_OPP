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
	int days = 30 + ((m + m / 8) % 2);

	if (m == 2)
		days = isLeapYear(y) ? 29 : 28;

	return days;
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
}

void DateTime::basicFormat() {
	cout << day << '.' << month << '.' << year << endl;
}

void DateTime::shortformat() {
	cout << day << month;

}

