#ifndef TESTDATA_GENERATOR_H
#define TESTDATA_GENERATOR_H

#include <string>
#include <fstream>
#include "N_random.cpp"

class TestDataGenerator {
  private:
    // What data members will you need?
    // Add any private helper functions you want
    const std::string ticker;
    double sigma; //per month
    double returns; //per month
    double initial_price;
    double end_price;
    int timeElapsed;
    N_random X;

// sigma = sd of per month percentage change of the security 

  public:
    TestDataGenerator();
    TestDataGenerator(double i, double r, double s, std::string t) 
        : ticker(t),
          X(pow(r,1/(22*7*60))-1, s/sqrt(22*7*60))
    {
        initial_price = i;
	    end_price =i;
        returns = r;
	    sigma = s;
    }; //stochastic process

    // The client, i.e. a main function you wrote, may call the tick function to retrieve the next tick data
    // A random amount of time r should elapse between each tick;
    
    const std::string tick();

    friend std::ostream& operator<< (std::ostream& stream, const TestDataGenerator& TDG); 
    
    void to_file(int n){
        time_t rawtime;
        time(&rawtime);

        std::string filename = ctime(&rawtime);
        filename = filename.substr(0, filename.size() - 1);
        std::ofstream file(filename);
        
        if (!file.is_open()) {
            std:: cout << "Unable to open the file." << std:: endl;
        }
        else {
            for (int i = 0; i < n; i++){
                tick();
                file << *this;
            }
        }

        file.close();
    }

    const std::string getTicker(){
        return ticker;
    }

    double getCurrentPrice(){
        return end_price;
    }

    double getCurrentVolume(){};

    double getSigma(){
        return sigma;
    }
    double gettimeElapsed(){
    	return timeElapsed;
    }

};

int main(){
    TestDataGenerator hello = TestDataGenerator(100.0, 1.2, 0.3, "GDX");
    hello.to_file(100000);
    
}

#endif
