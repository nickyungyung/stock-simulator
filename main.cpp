#include "TestDataGenerator.h"
#include <iostream>
#include <cmath>

int main()
{
    double mu = 0;
    int a;
    int runs = 1000;

    for (int i = 0; i < runs; i++){
        TestDataGenerator tdg = TestDataGenerator(100.0, 1.8, 0.5, "GDX");
        for (int i = 0; i < 9240; i++){
            tdg.tick();
        }
        std::cout << tdg.getCurrentPrice();
        std::cout << std::endl;
        // mu += tdg.getCurrentPrice();
    }

    // std::cout << "Mean monthly return of " << runs << " sims: " << mu/runs;
    // std::cout << std::endl;

    return 0;
}