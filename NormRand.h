#pragma once
#ifndef NormRand_H
#define NormRand_H

class NormRand {
private:
    double mean;
    double sigma;
    double X;           // a random sample from then distribution
    int counter = 0;    // holds reroll parameters
    int i = 0;          // holds reroll parameters
    int random_seed;

public:
    // Constructor initialize mean, sigma and generates and X
    NormRand(double m, double s, int r);

    void reroll();
    void printX();
    double getX();
};

#endif
