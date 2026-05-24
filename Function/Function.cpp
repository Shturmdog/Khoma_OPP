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

// Численное дифференцирование 
double Parabola::diff(double x, double eps) const {
    return 2 * x + b;
}

// Аналитическое интегрирование (первообразная)
double Parabola::integrate(double left, double right, double eps) const {
    double F_right = a * pow(right, 3) / 3 + b * right * right / 2 + c * right;
    double F_left = a * pow(left, 3) / 3 + b * left * left / 2 + c * left;
    return F_right - F_left;  // Определённый интеграл
}

void Parabola::printInfo() const {
    cout << "Parabola: f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}


Hyperbola::Hyperbola(double A, double B, double C) : a(A), b(B), c(C) {}

// Вычисление значения функции с проверкой особой точки
double Hyperbola::getValue(double x) const {
    double denominator = x + b;
    if (fabs(denominator) < 1e-12) {
        return NAN;  // Особенность (деление на ноль)
    }
    return a / denominator + c;
}


void Hyperbola::printResult(double x) const {
    double val = getValue(x);
    if (isnan(val))
        cout << "Hyperbola: f(" << x << ") = undefined (division by zero)" << endl;
    else
        cout << "Hyperbola: f(" << x << ") = " << val << endl;
}

// Вспомогательная функция: проверяет, есть ли особая точка внутри интервала
static bool hasSingularity(double left, double right, double b) {
    double singular = -b;
    return (singular > left && singular < right);
}

double Hyperbola::findMin(double left, double right, double eps) const {
    // Если на интервале есть разрыв, поиск некорректен – возвращаем NaN
    if (hasSingularity(left, right, b)) {
        cout << "Warning: singularity inside interval, cannot find min" << endl;
        return NAN;
    }

    double phi = (1 + sqrt(5)) / 2;
    double l = left, r = right;
    double c = r - (r - l) / phi;
    double d = l + (r - l) / phi;

    while (fabs(c - d) > eps) {
        double fc = getValue(c);
        double fd = getValue(d);
        if (isnan(fc) || isnan(fd)) break; // защита
        if (fc < fd)
            r = d;
        else
            l = c;
        c = r - (r - l) / phi;
        d = l + (r - l) / phi;
    }
    return getValue((l + r) / 2);
}

// Поиск максимума (аналогично)
double Hyperbola::findMax(double left, double right, double eps) const {
    if (hasSingularity(left, right, b)) {
        cout << "Warning: singularity inside interval, cannot find max" << endl;
        return NAN;
    }

    double phi = (1 + sqrt(5)) / 2;
    double l = left, r = right;
    double c = r - (r - l) / phi;
    double d = l + (r - l) / phi;

    while (fabs(c - d) > eps) {
        double fc = getValue(c);
        double fd = getValue(d);
        if (isnan(fc) || isnan(fd)) break;
        if (fc > fd)
            r = d;
        else
            l = c;
        c = r - (r - l) / phi;
        d = l + (r - l) / phi;
    }
    return getValue((l + r) / 2);
}

double Hyperbola::integrate(double left, double right, double eps) const {
    // Если на интервале есть особая точка – интеграл расходится
    if (hasSingularity(left, right, b)) {
        cout << "Warning: singularity inside interval, integral diverges" << endl;
        return NAN;
    }

    int n = 1000;  // количество подынтервалов
    double h = (right - left) / n;
    double sum = getValue(left) + getValue(right);
    if (isnan(sum)) return NAN;

    for (int i = 1; i < n; i++) {
        double x = left + i * h;
        double val = getValue(x);
        if (isnan(val)) return NAN;
        if (i % 2 == 0)
            sum += 2 * val;
        else
            sum += 4 * val;
    }
    return sum * h / 3;
}

double Hyperbola::diff(double x, double eps) const {
    double denominator = x + b;
    if (fabs(denominator) < 1e-12) return NAN;
    return -a / (denominator * denominator);
}

void Hyperbola::printInfo() const {
    cout << "Hyperbola: f(x) = " << a << " / (x + " << b << ") + " << c << endl;
}

Exponenta::Exponenta(double A, double B, double C) : a(A), b(B), c(C) {}

// Вычисление значения функции: a * exp(b*x) + c
double Exponenta::getValue(double x) const {
    return a * exp(b * x) + c;
}

void Exponenta::printResult(double x) const {
    cout << "Exponenta: f(" << x << ") = " << getValue(x) << endl;
}

double Exponenta::findMin(double left, double right, double eps) const {
    double phi = (1 + sqrt(5)) / 2;
    double l = left, r = right;
    double c_val = r - (r - l) / phi;
    double d_val = l + (r - l) / phi;

    while (fabs(c_val - d_val) > eps) {
        double fc = getValue(c_val);
        double fd = getValue(d_val);
        if (fc < fd)
            r = d_val;
        else
            l = c_val;
        c_val = r - (r - l) / phi;
        d_val = l + (r - l) / phi;
    }
    return getValue((l + r) / 2);
}

// Поиск максимума 
double Exponenta::findMax(double left, double right, double eps) const {
    double phi = (1 + sqrt(5)) / 2;
    double l = left, r = right;
    double c_val = r - (r - l) / phi;
    double d_val = l + (r - l) / phi;

    while (fabs(c_val - d_val) > eps) {
        double fc = getValue(c_val);
        double fd = getValue(d_val);
        if (fc > fd)
            r = d_val;
        else
            l = c_val;
        c_val = r - (r - l) / phi;
        d_val = l + (r - l) / phi;
    }
    return getValue((l + r) / 2);
}

// Аналитическое интегрирование 
double Exponenta::integrate(double left, double right, double) const {
    if (fabs(b) < 1e-12) {  // если b=0, экспонента вырождается в константу
        return (a + c) * (right - left);
    }
    // Вычисляем первообразную в точках right и left напрямую
    double F_right = (a / b) * exp(b * right) + c * right;
    double F_left = (a / b) * exp(b * left) + c * left;
    return F_right - F_left;
}

// Аналитическая производная: f'(x) = a * b * exp(b*x)
double Exponenta::diff(double x, double eps) const {
    return a * b * exp(b * x);
}

void Exponenta::printInfo() const {
    cout << "Exponenta: f(x) = " << a << " * exp(" << b << " * x) + " << c << endl;
}