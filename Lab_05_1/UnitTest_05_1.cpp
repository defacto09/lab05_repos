// UnitTest_05_1.cpp
// Unit-тест функції h() з Лабораторної роботи № 5.1

#define UNIT_TEST
#include "Lab_05_1.cpp"

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
    AreEqual("TestMethod1: h(1, 1, 1) = 1.5",  1.5,  h(1, 1, 1));
    AreEqual("TestMethod2: h(2, 1, 3) = 1.2",  1.2,  h(2, 1, 3));
    AreEqual("TestMethod3: h(0, 1, -1) = 0",   0.0,  h(0, 1, -1));
    AreEqual("TestMethod4: h(1, -2, 1) = 0",   0.0,  h(1, -2, 1));

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
