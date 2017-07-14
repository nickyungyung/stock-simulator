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
    time_elapsed{0},
X(0, 1, randomSeed)
{randomSeed += rand(); randomSeed = randomSeed%10000; }

int TestDataGenerator::randomSeed {0};

const std::string TestDataGenerator::tick()
{
    initial_price = end_price;
    X.reroll();

    int interval; // interval is a random amount of seconds between 1-10
    srand(time(NULL));
    interval = rand() % 10 +1;

    interval = 1; // interval set to be 1 for now

    time_elapsed += interval;

    double second_sigma = sigma/sqrt(22*7*60); //including the adjustment for interval
    double x = log(returns/sqrt(1+sigma*sigma/returns*returns))/(22*7*60)*interval + second_sigma* X.getX()* sqrt(interval);
    double change = initial_price*(x);
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
