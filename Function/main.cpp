#include <iostream>
#include "Function.h"
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Создаём параболу
    Parabola p(1, -3, 2);

    // Вывод информации о функции
    p.printInfo();
    cout << endl;

    // Вычисляем значения в точках
    cout << "Значения функции:" << endl;
    p.printResult(0);
    p.printResult(1);
    p.printResult(2);
    p.printResult(3);
    cout << endl;

    // Поиск минимума и максимума на интервале [0, 3]
    double left = 0, right = 3;
    cout << "На интервале [" << left << ", " << right << "]:" << endl;
    cout << "Минимум: " << p.findMin(left, right) << endl;
    cout << "Максимум: " << p.findMax(left, right) << endl;
    cout << "\n";

    //Интегрирование
    cout << "Интегрирование" << endl;
    cout << "Интеграл от 0 до 2: " << p.integrate(0, 2) << endl;
    cout << "\n";

    // Дифференцирование
    cout << "Дифференцирование" << endl;
    cout << "Производная в x=1: " << p.diff(1) << endl;
    cout << "Производная в x=2: " << p.diff(2) << endl;

    Hyperbola h(2, -1, 3);

    h.printInfo();
    cout << endl;

    // Значения в точках
    h.printResult(0);
    h.printResult(2);
    h.printResult(1);
    cout << endl;

    // Минимум на интервале [1.5, 5]
    double h_left = 1.5, h_right = 5;
    cout << "On interval [" << h_left << ", " << h_right << "]:" << endl;
    cout << "Minimum: " << h.findMin(h_left, h_right) << endl;
    cout << "Maximum: " << h.findMax(h_left, h_right) << endl;
    cout << endl;

    // Интеграл от 2 до 4
    cout << "Integral from 2 to 4: " << h.integrate(2, 4) << endl;

    // Производная в точке x=3
    cout << "Derivative at x=3: " << h.diff(3) << endl;

    Exponenta e(2, 0.5, 1);  // 2 * exp(0.5*x) + 1
    e.printInfo();
    e.printResult(0);
    cout << "Integral from 0 to 1: " << e.integrate(0, 1) << endl;
    cout << "Derivative at x=0: " << e.diff(0) << endl;
    return 0;
}

