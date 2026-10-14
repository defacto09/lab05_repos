// UnitTest_05_5.cpp
// Unit-тест функції f() з Лабораторної роботи № 5.5

#define UNIT_TEST
#include "Lab_05_5.cpp"

int passed = 0, failed = 0;

// аналог Assert::AreEqual для цілих чисел
void AreEqual(const char* name, int expected, int actual)
{
    if (expected == actual)
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
    int depth;

    depth = 0;
    AreEqual("TestMethod1: f(12345) = 15", 15, f(12345, 1, depth));
    AreEqual("TestMethod2: depth(12345) = 6", 6, depth);

    depth = 0;
    AreEqual("TestMethod3: f(7) = 7", 7, f(7, 1, depth));
    AreEqual("TestMethod4: depth(7) = 2", 2, depth);

    depth = 0;
    AreEqual("TestMethod5: f(1000) = 1", 1, f(1000, 1, depth));
    AreEqual("TestMethod6: depth(1000) = 5", 5, depth);

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
