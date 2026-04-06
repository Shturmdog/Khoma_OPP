#pragma once
#include <iostream>

class DateTime {
	int year, month, day;

	bool isLeapYear(int y) const;
	int daysInMonth(int y, int m) const;
public:
	DateTime();
	int DateEaster();
	void input();
};

