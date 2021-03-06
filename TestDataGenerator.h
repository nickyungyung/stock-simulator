#pragma once
#ifndef TestDataGenerator_H
#define TestDataGenerator_H

#include <string>
#include "NormRand.h"

class TestDataGenerator {
private:
    const std::string ticker;
    const double sigma;   // per month
    const double returns; // per month
    const double initial_price;
    double total_change;
    double last_change;
    int time_elapsed;
    static int random_seed;
    NormRand norm_rand;

public:
    TestDataGenerator();
    TestDataGenerator(double i, double r, double s, std::string t);

    // The client, i.e. a main function you wrote, may call the tick function
    // to retrieve the next tick data. A random amount of time should elapse
    // between each tick;
    void tick();
    friend std::ostream& operator<<(std::ostream& stream, const TestDataGenerator& tdg);

    void toFile(int n);
    std::string getTicker() const;
    double getSigma() const;
    double getCurrentPrice() const;
    double getCurrentVolume() const;
    double getTotalChange() const;
    double getLastChange() const;
    int getTimeElapsed() const;
};



#endif
