#include "Shape.h"
using namespace std;

//Circle
Circle::Circle(double cx, double cy, double r)
    : center_x(cx), center_y(cy), radius(r) {
}

double Circle::calc_area() {
    return PI * radius * radius;
}

double Circle::calc_perimeter() {
    return 2 * PI * radius;
}

void Circle::name() {
    cout << "Circle" << endl;
}

// Ellipse
Ellipse::Ellipse(double cx, double cy, double ra, double rb)
    : center_x(cx), center_y(cy), radius_a(ra), radius_b(rb) {
}

double Ellipse::calc_area() {
    return PI * radius_a * radius_b;
}

double Ellipse::calc_perimeter() {
    double a = radius_a;
    double b = radius_b;
    double h = ((a - b) * (a - b)) / ((a + b) * (a + b));
    return PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}

void Ellipse::name() {
    cout << "Ellipse" << endl;
}

//Triangle
void Triangle::calc_side() {
    sideA = b.distance(c);
    sideB = a.distance(c);
    sideC = a.distance(b);
}

Triangle::Triangle(const Point<double>& p1, const Point<double>& p2, const Point<double>& p3)
    : a(p1), b(p2), c(p3) {
    calc_side();
}

Triangle::Triangle(const Point<int>& p1, const Point<int>& p2, const Point<int>& p3)
    : a(p1.x, p1.y), b(p2.x, p2.y), c(p3.x, p3.y) {
    calc_side();
}

Triangle::Triangle(const Point<float>& p1, const Point<float>& p2, const Point<float>& p3)
    : a(p1.x, p1.y), b(p2.x, p2.y), c(p3.x, p3.y) {
    calc_side();
}

bool Triangle::isValid() const {
    return (sideA + sideB > sideC) &&
        (sideA + sideC > sideB) &&
        (sideB + sideC > sideA) &&
        (sideA > 0 && sideB > 0 && sideC > 0);
}

double Triangle::calc_area() {
    if (!isValid()) return 0.0;
    double p = (sideA + sideB + sideC) / 2.0;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double Triangle::calc_perimeter() {
    return sideA + sideB + sideC;
}

void Triangle::name() {
    cout << "Triangle" << endl;
}

//Polygon
Polygon::Polygon(const Point<double> vx[], int count) {
    for (int i = 0; i < count; ++i)
        vertex.push_back(vx[i]);
}

Polygon::Polygon(const Point<int> vx[], int count) {
    for (int i = 0; i < count; ++i)
        vertex.push_back(Point<double>(vx[i].x, vx[i].y));
}

Polygon::Polygon(const Point<float> vx[], int count) {
    for (int i = 0; i < count; ++i)
        vertex.push_back(Point<double>(vx[i].x, vx[i].y));
}

double Polygon::calc_area() {
    if (vertex.size() < 3) return 0.0;
    double area = 0.0;
    for (size_t i = 0; i < vertex.size(); ++i) {
        size_t j = (i + 1) % vertex.size();
        area += vertex[i].x * vertex[j].y;
        area -= vertex[j].x * vertex[i].y;
    }
    return abs(area) / 2.0;
}

double Polygon::calc_perimeter() {
    if (vertex.size() < 3) return 0.0;
    double perim = 0.0;
    for (size_t i = 0; i < vertex.size(); ++i) {
        size_t j = (i + 1) % vertex.size();
        perim += vertex[i].distance(vertex[j]);
    }
    return perim;
}

void Polygon::name() {
    size_t n = vertex.size();
    if (n == 4) cout << "Quadrilateral";
    else if (n == 5) cout << "Pentagon";
    else if (n == 6) cout << "Hexagon";
    else cout << "Polygon";
    cout << endl;
}