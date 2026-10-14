// Lab_05_5.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 5.5 «Рекурсивні функції»
// Варіант 25: сума цифр натурального числа n
//             f(n) = n mod 10 + f(n / 10),  f(0) = 0

#include <iostream>

using namespace std;

// f – сума цифр числа n
// level – поточний рівень рекурсії (параметр-значення)
// depth – глибина рекурсії (параметр-посилання)
int f(const int n, const int level, int &depth)
{
    if (level > depth)
        depth = level;
    cout << "level = " << level << ", n = " << n << endl;

    if (n == 0)                                  // базова задача
        return 0;
    else
        return n % 10 + f(n / 10, level + 1, depth);   // рекурсивний виклик
}

#ifndef UNIT_TEST
int main()
{
    int n;
    do { cout << "n = "; cin >> n; } while (n < 1);     // натуральне число

    int depth = 0;                                      // початкове значення глибини
    int s = f(n, 1, depth);                             // 1 – початковий рівень

    cout << "sum of digits = " << s << endl;
    cout << "depth = " << depth << endl;
    return 0;
}
#endif
