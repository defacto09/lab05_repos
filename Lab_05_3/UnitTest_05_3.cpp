// UnitTest_05_3.cpp
// Unit-тест функції z() з Лабораторної роботи № 5.3

#define UNIT_TEST
#include "Lab_05_3.cpp"

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

// та сама сума без рекурентного співвідношення: x^j та (2j)! рахуються напряму
double zDirect(const double x)
{
    double S = 0;
    for (int j = 0; j <= 7; j++)
    {
        double f = 1;
        for (int i = 1; i <= 2 * j; i++)
            f *= i;
        S += pow(-1, j) * pow(x, j) / f;
    }
    return S * exp(x);
}

int main()
{
    AreEqual("TestMethod1: z(0) = 1", 1.0, z(0));
    AreEqual("TestMethod2: z(0.5) = direct sum", zDirect(0.5), z(0.5));
    AreEqual("TestMethod3: z(-0.9) = direct sum", zDirect(-0.9), z(-0.9));
    AreEqual("TestMethod4: z(2) = (1 - sin 2)/(e^2 + cos^2 2)",
             (1 - sin(2.0)) / (exp(2.0) + cos(2.0) * cos(2.0)), z(2));
    AreEqual("TestMethod5: z(-1) (branch |x| >= 1)",
             (1 - sin(-1.0)) / (exp(-1.0) + cos(1.0) * cos(1.0)), z(-1));

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
