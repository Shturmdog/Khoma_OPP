#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double PI = M_PI;

template<typename T>
class Point {
public:
	T x, y;
	Point(T x = 0, T y = 0) {
		this->x = x;
		this->y = y;
	}

	Point operator + (const Point& other) const {
		return Point(x + other.x, y + other.y);
	}

	Point operator - (const Point& other) const {
		return Point(x - other.x, y - other.y);
	}

	double distance(const Point& other) const {
		double dx = static_cast<double>(x - other.x);
		double dy = static_cast<double>(y - other.y);
		return sqrt(dx * dx + dy * dy);
	}
};

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


class Triangle : public Figure {
	double sideA, sideB, sideC;
	Point<double> a, b, c;

	void calc_side() {
		sideA = b.distance(c);
		sideB = a.distance(c);
		sideC = a.distance(b);

public:
	Triangle(const Point<double>&p1, const Point<double>&p2, const Point<double>&p3) {
		a = p1;
		b = p2;
		c = p3;
		calc_side();
	}

	Triangle(const Point<int>& p1, const Point<int>& p2, const Point<int>& p3) {
		a = Point<double>(p1.x, p1.y);
		b = Point<double>(p2.x, p2.y);
		c = Point<double>(p3.x, p3.y);
		calc_side();
	}

	Triangle(const Point<float>& p1, const Point<float>& p2, const Point<float>& p3) {
		a = Point<double>(p1.x, p1.y);
		b = Point<double>(p2.x, p2.y);
		c = Point<double>(p3.x, p3.y);
		calc_side();
	}

	double calc_perimeter() const {
		return sideA + sideB + sideC;
	}
};
