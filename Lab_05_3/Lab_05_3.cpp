// Lab_05_3.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 5.3 «Функції, що містять розгалуження та цикли
//                          з рекурентними співвідношеннями»
// Варіант 25: y = z(1 - k^2) + z^2(1 + z(k))

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double z(const double x);

#ifndef UNIT_TEST
int main()
{
    double kp, kk, k, y;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    do { cout << "n = "; cin >> n; } while (n <= 0);   // кількість відрізків

    double dk = (kk - kp) / n;                         // крок

    cout << fixed;
    cout << "Table: y = z(1 - k^2) + z^2(1 + z(k))" << endl;
    cout << "---------------------------" << endl;
    cout << "|" << setw(8) << "k" << " |" << setw(13) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        k = kp + i * dk;
        y = z(1 - k * k) + pow(z(1 + z(k)), 2);
        cout << "|" << setw(8) << setprecision(3) << k << " |"
             << setw(13) << setprecision(6) << y << " |" << endl;
    }
    cout << "---------------------------" << endl;
    return 0;
}
#endif

// z(x) = (1 - sin x) / (e^x + cos^2 x),                      |x| >= 1
// z(x) = 1 / e^(-x) * sum_{j=0}^{7} (-1)^j x^j / (2j)!,        |x| < 1
double z(const double x)
{
    if (fabs(x) >= 1)
        return (1 - sin(x)) / (exp(x) + cos(x) * cos(x));
    else
    {
        int j = 0;
        double a = 1;           // перший доданок (j = 0): 1
        double S = a;
        do
        {
            j++;
            double R = -x / ((2 * j - 1) * (2 * j));   // a(j) = a(j-1) * R
            a *= R;
            S += a;
        } while (j < 7);
        return S / exp(-x);
    }
}
