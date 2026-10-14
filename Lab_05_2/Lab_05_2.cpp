// Lab_05_2.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 5.2 «Обчислення суми ряду Тейлора за допомогою функцій»
// Варіант 25: ln((1 + x) / (1 - x)) = 2 * (x + x^3/3 + x^5/5 + ...), |x| < 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    do { cout << "xp = "; cin >> xp; } while (!(-1 < xp && xp < 1));
    do { cout << "xk = "; cin >> xk; } while (!(-1 < xk && xk < 1));
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "ln(...)" << " |"
         << setw(10) << "S" << " |"
         << setw(5) << "n" << " |" << endl;
    cout << "---------------------------------------------" << endl;

    x = xp;
    while (x <= xk + 1e-9)          // 1e-9 – запас на похибку
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
             << setw(10) << setprecision(5) << s << " |"
             << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "---------------------------------------------" << endl;
    return 0;
}
#endif

// S – сума ряду з точністю eps; n – кількість обчислених доданків після першого
void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = x;           // перший доданок (n = 0): x^1 / 1
    s = a;
    do
    {
        n++;
        A(x, n, a);         // a(n) = a(n-1) * R
        s += a;
    } while (fabs(a) >= eps);
    s *= 2;                 // множник 2 перед сумою
}

// A – наступний доданок через рекурентне співвідношення
void A(const double x, const int n, double &a)
{
    double R = x * x * (2 * n - 1) / (2 * n + 1);
    a *= R;
}
