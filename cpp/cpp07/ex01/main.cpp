#include "iter.hpp"

int	main( void ) {
	std::string test[] = {
		"test1",
		"test2",
		"test3"
	};

	/* int test[] = {
		1, 2, 3, 4, 5
	}; */

	/* char test[] = {
		'a', 'b', 'c'
	}; */
	
	::iter(test, sizeof(test) / sizeof(test[0]), &::func);
	
	return 0;
}