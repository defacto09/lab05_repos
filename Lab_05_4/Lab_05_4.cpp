// Lab_05_4.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 5.4 «Обчислення сум та добутків за допомогою рекурсії»
// Варіант 25: P = добуток від k = N до 19 виразу ((k - N) / (k + N) + 1)

#include <iostream>
#include <iomanip>

using namespace std;

// P0 – ітераційний спосіб (для контролю)
double P0(const int N, const int kmax)
{
    double p = 1;
    for (int k = N; k <= kmax; k++)
        p *= 1. * (k - N) / (k + N) + 1;
    return p;
}

// P1 – обчислення на рекурсивному спуску, параметр k спадає
double P1(const int N, const int kmax, const int k, double t)
{
    t *= 1. * (k - N) / (k + N) + 1;
    if (k <= N)
        return t;
    else
        return P1(N, kmax, k - 1, t);
}

// P2 – обчислення на рекурсивному спуску, параметр k зростає
double P2(const int N, const int kmax, const int k, double t)
{
    t *= 1. * (k - N) / (k + N) + 1;
    if (k >= kmax)
        return t;
    else
        return P2(N, kmax, k + 1, t);
}

// P3 – обчислення на рекурсивному підйомі, параметр k спадає
double P3(const int N, const int kmax, const int k)
{
    if (k < N)
        return 1;
    else
        return (1. * (k - N) / (k + N) + 1) * P3(N, kmax, k - 1);
}

// P4 – обчислення на рекурсивному підйомі, параметр k зростає
double P4(const int N, const int kmax, const int k)
{
    if (k > kmax)
        return 1;
    else
        return (1. * (k - N) / (k + N) + 1) * P4(N, kmax, k + 1);
}

#ifndef UNIT_TEST
int main()
{
    const int kmax = 19;
    int N;

    // N має бути в межах 1 <= N <= 19
    do { cout << "N = "; cin >> N; } while (N < 1 || N > kmax);

    cout << fixed << setprecision(6);
    cout << "(iter)            P0 = " << P0(N, kmax) << endl;
    cout << "(rec descent --)  P1 = " << P1(N, kmax, kmax, 1) << endl;
    cout << "(rec descent ++)  P2 = " << P2(N, kmax, N, 1) << endl;
    cout << "(rec ascent --)   P3 = " << P3(N, kmax, kmax) << endl;
    cout << "(rec ascent ++)   P4 = " << P4(N, kmax, N) << endl;
    return 0;
}
#endif
