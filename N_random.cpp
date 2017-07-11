#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

class N_random {
	private:
		double mean;
		double sigma;
		double X;
		int counter = 0; //for holding reroll parameters
		int i = 0; // for holding reroll parameters
		
		void vary_i(){
			i = i+1;
		}
	public:
		//constructor that takes in argument to initialize double mean and double sigma, generates X
		N_random(double a, double b){
			mean = a;
			sigma = b;
			
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std:: default_random_engine generator (seed);
			std:: normal_distribution<double> distribution(mean, sigma);
			X = distribution(generator);
		}
		
		//reroll possess a counter that varies according to i and time(NULL); i is varied by function vary_i when the function is called, time(null) varies when the function is compiled at different system time
		void reroll(){
			vary_i();
			counter +=(i + time(NULL));
			counter = counter%10000; //%10000 as to limit counter size, randomness perserved
			
			srand(counter);
			std:: default_random_engine generator (rand());
			std:: normal_distribution<double> distribution(mean, sigma);
			X = distribution(generator); //update the value of X based on the parameters of object, or "rerolling"
		}
		
		//get_X prints out the current X value
		void get_X(){
			std:: cout << X << std::endl;
		}
		//return_X returns a double copy of the X value of the object
		double return_X(){
			return X;
		}
};
