#include <iostream>
#include <vector>

template <typename T>
void	func( T begin, T end ) {
	for (begin; begin != end; begin++)
		std::cout << *begin << std::endl;
	return ;
}

int	main( void ) {
	func({1, 10, 3, 20});

	return 0;
}
