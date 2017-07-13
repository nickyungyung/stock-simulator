#include "TestDataGenerator.h"
#include <string>

const std::string TestDataGenerator::tick() {
    
    initial_price = end_price;
    X.reroll();
    
    int interval; //interval denotes a random time in seconds between 1-10
    srand(time(NULL));
    interval = rand() %10 +1;
    
    timeElapsed += interval;

    double second_sigma = sqrt(log(1+1/(pow((1+ log(returns)/(22*7*60)),2)/pow(sigma/sqrt(22*7*60),2))))/sqrt(22*7*60);
    double change = initial_price*(log((1+ log(returns)/(22*7*60))/sqrt(1+1/(pow(1+ log(returns)/(22*7*60),2)/pow(sigma/sqrt(22*7*60),2)))))*interval + second_sigma*X.return_X()*sqrt(interval);
    
    end_price += change;
    
    return ticker + " " + std::to_string(end_price);
}

std::ostream& operator<< (std::ostream& stream, const TestDataGenerator& TDG) {
    stream << TDG.ticker << ' ' << TDG.end_price << std::endl;
    stream << TDG.timeElapsed << std::endl;
}
