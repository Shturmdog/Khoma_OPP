#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
	virtual double calc_area() = 0;
	virtual double calcl_perimetr() = 0;
	virtual void name() = 0;
};

class Circle : public Figure {
	double center_x;
	double center_y;
	double radius;
public:
	Circle(double cx, double cy, double r) {
		center_x = cx;
		center_y = cy;
		radius = r;
	}

	double calc_area() {
		return PI * radius * radius;
	}

	double calc_perimetr() {
		return 2 * PI * radius;
	}

	void name() {
		cout << "Circle" << endl;
	}
};

class Elipse : public Figure {
	double center_x;
	double center_y;
	double radius_a;
	double radius_b;
public:
	Elipse(double cx, double cy, double ra, double rb) {
		center_x = cx;
		center_y = cy;
		radius_a = ra;
		radius_b = rb;
	}

	double calc_area() {
		return PI * radius_a * radius_b;
	}

	double calc_perimetr() {
		double a = radius_a;
		double b = radius_b;
		double h = ((a - b) * (a - b)) / ((a + b) * (a + b));
		return PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
	}

	void name() {
		cout << "Elipse" << endl;
	}
};
