#include "TestDataGenerator.h"
#include <string>

const std::string TestDataGenerator::tick() {
    
    initial_price = end_price;
    X.reroll();
    
    int interval; //interval denotes a random time in seconds between 1-10
    srand(time(NULL));
    interval = rand() %10 +1;
    
    timeElapsed += interval;

    double second_sigma = sigma/sqrt(22*7*60*60);
    double change = initial_price*((pow(pow(returns,1/(22*7*60*60)),interval)-1)*interval + second_sigma*X.return_X()*sqrt(interval));
    end_price += change;
    
    return ticker + " " + std::to_string(end_price);
}

std::ostream& operator<< (std::ostream& stream, const TestDataGenerator& TDG) {
    stream << TDG.ticker << ' ' << TDG.end_price << std::endl;
    stream << TDG.timeElapsed << std::endl;
}