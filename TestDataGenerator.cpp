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
    time_elapsed(0),
    norm_rand(0, 1, random_seed)
{
    random_seed += rand();
    random_seed %= 10000;
}

int TestDataGenerator::random_seed {0};

double TestDataGenerator::tick()
{
    norm_rand.reroll();

    int interval; // interval is a random amount of seconds between 1-10
//    srand(time(NULL));
//    interval = rand() % 10 +1;

    interval = 1; // interval set to be 1 for now
    time_elapsed += interval;

    double tau = (double) 1 / (22 * 7 * 60);

    double x = log(returns)*tau*interval + sigma*norm_rand.getX()*tau*interval;
    last_change = x * end_price;
    end_price += last_change;

    return end_price;
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

double TestDataGenerator::getSigma() const
{
    return sigma;
}

double TestDataGenerator::getCurrentPrice() const
{
    return end_price;
}

double TestDataGenerator::getCurrentVolume() const
{
    return sigma;
}

double TestDataGenerator::getLastChange() const
{
    return last_change;
}

int TestDataGenerator::getTimeElapsed() const
{
    return time_elapsed;
}

std::ostream& operator<<(std::ostream& stream, const TestDataGenerator& tdg)
{
    stream << tdg.getTimeElapsed() << ' ' << tdg.getTicker() << ' ' << tdg.getCurrentPrice() << std::endl;
}
