#include "utils.hpp"

Base::~Base( void ) {};

// utilities
class	Base;

typedef struct s_node {
	size_t	index;
	Base*	(*f)(void);
}	t_node;

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
	t_node			generateDerive[] = {
						{0, generateA},
						{1, generateB},
						{2, generateC},
					};
	
	return generateDerive[i].f();
}

void	identity( Base* p ) {
	A*	a;
	B*	b;
	C*	c;

	// dynamic_cast does run-time checking (RTTI)
		// we can check if cast is done.
		// for our use to check the identity of the base class pointer.
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
