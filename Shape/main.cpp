#define _USE_MATH_DEFINES	
#include <iostream>
#include "Shape.h"
int main() {
	Circle c(1, 2, 7);

	cout << "Testing Circle (radius = 7):\n";
	cout << "  Name: ";
	c.name();
	cout << "\n  Area: " << c.calc_area();
	cout << "\n  Perimeter: " << c.calc_perimetr();
	cout << "\n\n";

	return 0;
}