#ifndef	UTILS_HPP
#define UTILS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime> // time
#include <cstdlib> // rand and srand

class RandomGenerator {
public:
	RandomGenerator() {
		// generate new sequence of random numbers
		std::srand(std::time(0));
	}

	int getRandomNumber(int min, int max) {
		return min + std::rand() % (max - min + 1);
	}
};

Base*	generate( void );
void	identity( Base* p );

#endif /* UTILS_HPP */
