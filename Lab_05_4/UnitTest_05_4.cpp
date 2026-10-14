// UnitTest_05_4.cpp
// Unit-тест функцій P0–P4 з Лабораторної роботи № 5.4

#define UNIT_TEST
#include "Lab_05_4.cpp"
#include <cmath>
#include <cstdio>

int passed = 0, failed = 0;

// аналог Assert::AreEqual для дійсних чисел (з точністю eps)
void AreEqual(const char* name, double expected, double actual, double eps = 1e-9)
{
    if (fabs(expected - actual) < eps)
    {
        cout << "[ PASSED ] " << name << endl;
        passed++;
    }
    else
    {
        cout << "[ FAILED ] " << name << ": expected " << expected
             << ", actual " << actual << endl;
        failed++;
    }
}

int main()
{
    // N = 19: один множник (0 / 38 + 1) = 1
    AreEqual("TestMethod1: P0(19) = 1", 1.0, P0(19, 19));
    // N = 18: множники 1 та (1 / 37 + 1) = 38 / 37
    AreEqual("TestMethod2: P0(18) = 38/37", 38.0 / 37, P0(18, 19));
    // усі рекурсивні способи збігаються з ітераційним
    for (int N = 1; N <= 19; N += 9)             // N = 1, 10, 19
    {
        double p = P0(N, 19);
        char name[60];
        snprintf(name, 60, "TestMethod3: N = %d: P1 = P0", N);
        AreEqual(name, p, P1(N, 19, 19, 1));
        snprintf(name, 60, "TestMethod4: N = %d: P2 = P0", N);
        AreEqual(name, p, P2(N, 19, N, 1));
        snprintf(name, 60, "TestMethod5: N = %d: P3 = P0", N);
        AreEqual(name, p, P3(N, 19, 19));
        snprintf(name, 60, "TestMethod6: N = %d: P4 = P0", N);
        AreEqual(name, p, P4(N, 19, N));
    }

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
