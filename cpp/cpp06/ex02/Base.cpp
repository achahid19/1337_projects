#include "utils.hpp"

Base::~Base( void ) {};

// utilities
class	Base;

static Base*	generateA( void ) {
	return new A();
}

static Base*	generateB( void ) {
	return new B();
}

static Base*	generateC( void ) {
	return new C();
}

Base*	generate( void ) {
	RandomGenerator	math;
	int 			i = math.getRandomNumber(0, 2);
	Base*			(*generateDerive[])(void) = {
						generateA,
						generateB,
						generateC,
					};
	
	return generateDerive[i]();
}

void	identity( Base* p ) {
	A*	a;
	B*	b;
	C*	c;

	a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "Type is: A!" << std::endl;
		return ;
	}
	b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "Type is: B!" << std::endl;
		return ;
	}
	c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "Type is: C!" << std::endl;
		return ;
	}
}
