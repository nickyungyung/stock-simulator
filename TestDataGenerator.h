#ifndef TESTDATA_GENERATOR_H
#define TESTDATA_GENERATOR_H

#include <string>
#include <iostream>

class TestDataGenerator{
  private:
    // What data members will you need?
    // Add any private helper functions you want
    const std::string ticker;
    double sigma;
    double mean;
    double price;
    double volume;

  public:
    TestDataGenerator();
    TestDataGenerator(double mean, double sigma, std::string ticker) { };
    ~TestDataGenerator();

    // The client, i.e. a main function you wrote, may call the tick function to retrieve the next tick data
    // A random amount of time should elapse between each tick;
    const std::string tick();
    std::istream& operator>> (std::ifstream& is, TestDataGenerator& tdg);
    friend std::ostream& operator<< (std::ofstream& os, TestDataGenerator& tdg);

    const std::string getTicker();
    double getSigma();
    double getMean();

    double getCurrentPrice();
    double getCurrentVolume();
};

#endif