#include "TestDataGenerator.h"

int main()
{
    TestDataGenerator tdg = TestDataGenerator(100.0,  1.8, 0.5, "GDX");
    tdg.toFile(9240);

    return 0;
}