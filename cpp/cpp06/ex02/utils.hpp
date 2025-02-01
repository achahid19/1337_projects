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
		/*
			Without srand() → The sequence of random numbers 
			is always the same every time you run the program.
			you can set a fixed seed, like srand(42),
			ensuring the same sequence is generated every time.
		*/
		std::srand(std::time(0));
	}

	int getRandomNumber(int min, int max) {
		return min + std::rand() % (max - min + 1);
		/*
				- Understanding std::rand() % (max - min + 1):
			*std::rand() generates a pseudo-random number in the range [0, RAND_MAX], where RAND_MAX is a large constant (typically 32767).
			*std::rand() % (max - min + 1) takes the modulo of the random number with (max - min + 1), which ensures that the result is within the range [0, max - min].
			*The reason for adding 1 in (max - min + 1) is to make the range inclusive of max. Without it, the maximum possible value would be max - 1.
				- Adding min:
			Since std::rand() % (max - min + 1) produces a number between 0 and (max - min), adding min shifts this range to [min, max].
		*/
	}
};

Base*	generate( void );
void	identity( Base* p );

#endif /* UTILS_HPP */
