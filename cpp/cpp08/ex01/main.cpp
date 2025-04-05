#include "Span.hpp"

int	main( void ) {
	Span			obj(100);
	std::set<int>	nums;

	obj.generateUniqueRandomNums(nums, 10, 1000);
	try {
		obj.fill(nums.begin(), nums.end());
		std::cout << "Container elements: ";
		for (
			std::vector<unsigned int>::const_iterator it = obj.begin();
			it != obj.end();
			it++
		) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		size_t shortesSpan = obj.shortestSpan();
		std::cout << "Shortest Span: " << shortesSpan << std::endl;

		size_t longestSpan = obj.longestSpan();
		std::cout << "Longest Span: " << longestSpan << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
