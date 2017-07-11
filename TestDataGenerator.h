#ifndef TESTDATA_GENERATOR_H
#define TESTDATA_GENERATOR_H

#include <string>

class TestDataGenerator {
  private:
    // What data members will you need?
    // Add any private helper functions you want
    const std::string ticker;
    double sigma; //per month
    double returns; //per month
    double initial_price;
    double end_price = initial_price;
    int timeElapsed = 0;
    N_random X((returns-1)*initial_price, sigma/sqrt(22*7*60*60)); 
    
// sigma = sd of per month percentage change of the security 

  public:
    TestDataGenerator();
    TestDataGenerator(double i, double r, double s, std::string t) {
        initial_price = i;
	    returns = r;
	    sigma = s;
    	ticket = t;
    }; //stochastic process

    // The client, i.e. a main function you wrote, may call the tick function to retrieve the next tick data
    // A random amount of time r should elapse between each tick;
    
    const std::string tick();

    friend ostream& operator<< (ostream& stream, const TestDataGenerator& TDG); 
    
    void to_file(int n, const TestDataGenerator& TDG){
        time_t rawtime;
        time(&rawtime);

        std::string filename = ctime(&rawtime);
        ofstream file(filename);
        
        if(!file.is_open()){std:: cout << "Unable to open the file." << std:: endl;}
        else {
            for (int i = 0; i < n; i++){
                tick();
            file << &this;
            }
        }
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
    double gettimeElaspsed(){
    	return timeElapsed;
    }

};

int main(){
    TestDataGenerator(100, 0.03, "GDX");
}

#endif
