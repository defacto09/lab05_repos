// UnitTest_05_2.cpp
// Unit-тест функцій S() та A() з Лабораторної роботи № 5.2

#define UNIT_TEST
#include "Lab_05_2.cpp"

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
    // A: другий доданок для x = 0.5 – це 0.5^3 / 3
    double a = 0.5;
    A(0.5, 1, a);
    AreEqual("TestMethod1: A(0.5, 1, a=0.5) = 0.125/3", 0.125 / 3, a);

    // S: сума ряду при x = 0 дорівнює 0, обчислено 1 доданок після першого
    int n;
    double s;
    S(0, 1e-6, n, s);
    AreEqual("TestMethod2: S(0) = 0", 0.0, s);
    AreEqual("TestMethod3: S(0): n = 1", 1, n);

    // S: при x = 0.5 сума має збігатися з ln(3) з точністю 1e-6
    S(0.5, 1e-8, n, s);
    AreEqual("TestMethod4: S(0.5) = ln(3)", log(3.0), s, 1e-6);

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
