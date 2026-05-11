#include <iostream>
#include <cmath>
#include "Function.h"
using namespace std;

Parabola::Parabola(double A, double B, double C) {
	a = A;
	b = B;
	c = C;
}

// Вычисление значения функции в точке x
double Parabola::getValue(double x) const {
	return a * x * x + b * x + c;
}

// Вывод значения функции на экран
void Parabola::printResult(double x) const {
	cout << "Parabola: f(" << x << ") = " << getValue(x) << endl;
}

// Поиск минимума на интервале [left, right]
double Parabola::findMin(double left, double right, double eps) const {
	if (a > 0) {
		double vertex = -b / (2 * a);  // Вершина параболы
		if (vertex >= left && vertex <= right)
			return getValue(vertex);
	}
	else
		cout << "None";  // Ветви вниз - минимума нет (уходит в -∞)
}

// Поиск максимума на интервале [left, right]
double Parabola::findMax(double left, double right, double eps) const {
	if (a < 0) {
		double vertex = -b / (2 * a);  // Вершина параболы
		if (vertex >= left && vertex <= right)
			return getValue(vertex);
	}
	else
		return max(getValue(left), getValue(right));  // Максимум на границах
}

// Численное дифференцирование (приближённое)
double Parabola::diff(double x, double eps) const {
	return 2 * x + b;
}

// Аналитическое интегрирование (первообразная)
double Parabola::integrate(double left, double right, double eps) const {
	double F_right = a * pow(right, 3) / 3 + b * right * right / 2 + c * right;
	double F_left = a * pow(left, 3) / 3 + b * left * left / 2 + c * left;
	return F_right - F_left;  // Определённый интеграл = F(b) - F(a)
}

// Вывод формулы функции на экран
void Parabola::printInfo() const {
	cout << "Parabola: f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}