#include "TestDataGenerator.h"
#include <iostream>

int main()
{
    TestDataGenerator tdg = TestDataGenerator(100.0,  1.8, 0.5, "GDX");
    tdg.toFile(9240);

    double mu = 0;
    int a;
    for (int i = 0; i<10000;i++){
        TestDataGenerator hello = TestDataGenerator(100.0, 1.8, 0.5, "GDX");
        for (int i = 0; i < 9240; i++){
            hello.tick();
        }
        mu += hello.getCurrentPrice();
        std::cout << hello.getCurrentPrice() << std::endl;
    }
    std::cout <<std::endl << mu/10000 << std::endl;
    
    return 0;
}
