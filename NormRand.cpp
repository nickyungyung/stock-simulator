#include "NormRand.h"

#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

// Constructor that takes in argument to initialize double mean and
// double sigma, generates X
NormRand::NormRand(double m, double s, int r)
{
    mean = m;
    sigma = s;
    random_seed = r;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + random_seed;
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(mean, sigma);
    X = distribution(generator);
}

// Reroll possess a counter that varies according to i and time(NULL);
// i is varied by function vary_i when the function is called, time(null) varies
// when the function is compiled at different system time
void NormRand::reroll()
{
	++i;
	counter += (i + time(NULL)) + random_seed;
	counter = counter%rand(); //%10000 as to limit counter size, randomness perserved

	srand(counter);
	std::default_random_engine generator (rand());
	std::normal_distribution<double> distribution(mean, sigma);
	X = distribution(generator); //update the value of X based on the parameters of object, or "rerolling"
}

// printX prints out the current X value
void NormRand::printX(){
	std::cout << X << std::endl;
}

//getX returns a double copy of the X value of the object
double NormRand::getX(){
	return X;
}
