#ifndef  RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>

class Random { //Allows for random number generation
public:
	Random() { //Uses time as the seed for a random number generation
		std::srand(std::time(0));
	}

	Random(int seed) { //Uses a given seed to generate a number
		srand(seed);
	}

	int next_int(int n) { //Returns a random integer between 0 and N
		return int(next_double()*n);
	}

	double next_double(){ //Returns a random value between 0 and 1
		return double(rand()) / RAND_MAX;
	}
};
#endif // ! RANDOM_H_
