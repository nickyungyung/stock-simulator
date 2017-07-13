#include "TestDataGenerator.h"
#include <cmath>
#include <iostream>
#include <fstream>

TestDataGenerator::TestDataGenerator(double i, double r,  double s, std::string t) :
    ticker(t),
    sigma(s),
    returns(r),
    initial_price(i),
    end_price(i),
    X(0, 1)
{ }

const std::string TestDataGenerator::tick()
{
    initial_price = end_price;
    X.reroll();

    int interval; // interval is a random amount of seconds between 1-10
    srand(time(NULL));
    interval = rand() % 10 +1;

    interval = 1; // interval set to be 1 for now

    time_elapsed += interval;

    double second_sigma = sigma/sqrt(22*7*60);
    double change = initial_price*(log((1+ log(returns)/(22*7*60))/sqrt(1+1/(pow(1+ log(returns)/(22*7*60),2)/pow(sigma/sqrt(22*7*60),2))))*interval + second_sigma*X.getX()*sqrt(interval));

    end_price += change;

    return ticker + " " + std::to_string(end_price);
}

void TestDataGenerator::toFile(int n)
{
    double start = initial_price;
    time_t rawtime;
    time(&rawtime);

    std::string filename = ctime(&rawtime);
    filename = filename.substr(0, filename.size() - 1);
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Unable to open the file." << std:: endl;
    }
    else {
        for (int i = 0; i < n; i++){
            tick();
            file << *this;
        }
    }

    file << "The expected return of the generation is " << start * pow(returns,(time_elapsed/(22*7*60))) << "." << std::endl;
    file.close();
}

std::string TestDataGenerator::getTicker() const
{
    return ticker;
}

double TestDataGenerator::getCurrentPrice() const
{
    return end_price;
}

double TestDataGenerator::getCurrentVolume() const
{
    return sigma;
}

int TestDataGenerator::getTimeElapsed() const
{
    return time_elapsed;
}

std::ostream& operator<<(std::ostream& stream, const TestDataGenerator& tdg)
{
    stream << tdg.getTimeElapsed() << ' ' << tdg.getTicker() << ' ' << tdg.getCurrentPrice() << std::endl;
}