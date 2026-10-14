// Lab_05_1.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 5.1 «Функції, що містять арифметичний вираз»
// Варіант 25

#include <iostream>
#include <cmath>

using namespace std;

double h(const double x, const double y, const double z);   // прототип

#ifndef UNIT_TEST
int main()
{
    double a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    double d = h(1, a * b, 1);                     // знаменник виразу
    if (d == 0)                                    // при a*b = -2
        cout << "c: Gives no definition" << endl;
    else
    {
        double c = (h(a * a, 1, b) + h(b, 1, a * a)) / d;
        cout << "c = " << c << endl;
    }
    return 0;
}
#endif

// h(x, y, z) = (x + y + z) / (x^2 + y^2)
double h(const double x, const double y, const double z)   // визначення
{
    return (x + y + z) / (x * x + y * y);
}
