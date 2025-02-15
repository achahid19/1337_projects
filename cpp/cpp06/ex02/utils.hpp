#ifndef	UTILS_HPP
#define UTILS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

class RandomGenerator {
public:
	RandomGenerator() {
		std::srand(std::time(0));
	}

	int getRandomNumber(int min, int max) {
		return min + std::rand() % (max - min + 1);
	}
};

Base*	generate( void );
void	identity( Base* p );

#endif /* UTILS_HPP */
