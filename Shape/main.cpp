#include <iostream>
#include "Shape.h"

using namespace std;

int main() {
    Circle c(1, 2, 7);

    cout << "Testing Circle (radius = 7):\n";
    cout << "  Name: ";
    c.name();
    cout << "\n  Area: " << c.calc_area();
    cout << "\n  Perimeter: " << c.calc_perimeter();
    cout << "\n\n";

    Ellipse e(2, 5, 7, 6);

    cout << "Testing Ellipse (radius_a = 7, radius_b = 6):\n";
    cout << " Name: ";
    e.name();
    cout << "\n Area: " << e.calc_area();
    cout << "\n Perimeter: " << e.calc_perimeter();
    cout << "\n\n";

    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(0, 4);

    Triangle tr(p1, p2, p3);
    cout << "Testing Triangle:\n";
    cout << " Name: ";
    tr.name();
    cout << "\n Area: " << tr.calc_area();
    cout << "\n Perimeter: " << tr.calc_perimeter();
    cout << "\n\n";

    Point<double> quadPoints[] = {
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(4, 3),
        Point<double>(0, 3)
    };

    Polygon poly(quadPoints, 4);
    cout << "Testing Polygon:\n";
    cout << " Name: ";
    poly.name();
    cout << "\n Area: " << poly.calc_area();
    cout << "\n Perimeter: " << poly.calc_perimeter();
    cout << "\n\n";

    return 0;
}