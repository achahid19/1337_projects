#include "easyfind.hpp"
#include <vector>
#include <deque>

int	main( void ) {
	std::vector<int>				v;
	std::deque<int>					q(3, 10);
	std::vector<int>::iterator		it1;
	std::deque<int>::iterator		it2;

	v.push_back(50);
	q.push_front(100);
	try {
		it1 = easyfind(v, 50);
		std::cout << *it1 << std::endl;
		it2 = easyfind(q, 100);
		std::cout << *it2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
