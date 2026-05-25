#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>

// Гарантия наличия M_PI
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double PI = M_PI;

template<typename T>
class Point {
public:
    T x, y;
    Point(T x = 0, T y = 0);
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    double distance(const Point& other) const;
};

// Абстрактный базовый класс
class Figure {
public:
    virtual double calc_area() = 0;
    virtual double calc_perimeter() = 0;
    virtual void name() = 0;
    virtual ~Figure() = default;
};

class Circle : public Figure {
    double center_x;
    double center_y;
    double radius;
public:
    Circle(double cx, double cy, double r);
    double calc_area() override;
    double calc_perimeter() override;
    void name() override;
};

class Ellipse : public Figure {
    double center_x;
    double center_y;
    double radius_a;
    double radius_b;
public:
    Ellipse(double cx, double cy, double ra, double rb);
    double calc_area() override;
    double calc_perimeter() override;
    void name() override;
};

class Triangle : public Figure {
    double sideA, sideB, sideC;
    Point<double> a, b, c;

    void calc_side();
public:
    Triangle(const Point<double>& p1, const Point<double>& p2, const Point<double>& p3);
    Triangle(const Point<int>& p1, const Point<int>& p2, const Point<int>& p3);
    Triangle(const Point<float>& p1, const Point<float>& p2, const Point<float>& p3);

    bool isValid() const;
    double calc_area() override;
    double calc_perimeter() override;
    void name() override;
};

class Polygon : public Figure {
    std::vector<Point<double>> vertex;
public:
    Polygon(const Point<double> vx[], int count);
    Polygon(const Point<int> vx[], int count);
    Polygon(const Point<float> vx[], int count);

    double calc_area() override;
    double calc_perimeter() override;
    void name() override;
};

template<typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<typename T>
Point<T> Point<T>::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

template<typename T>
Point<T> Point<T>::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

template<typename T>
double Point<T>::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}