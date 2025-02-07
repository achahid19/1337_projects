#include "Span.hpp"

int	main( void ) {
	Span	obj(10000);

	try {
		for(size_t i = 1; i < obj.getSize() + 1; i++) {
			obj.addNumber(i); // TODO; avoid thousand of calls, implement range of iterators.
		}
		for (size_t i = 0; i < obj.getSize(); i++) {
			std::cout << obj[i] << std::endl;
		}
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	size_t shortesSpan = obj.shortestSpan();
	std::cout << "Shortest Span: " << shortesSpan << std::endl;
	
	size_t longestSpan = obj.longestSpan();
	std::cout << "Longest Span: " << longestSpan << std::endl;

	return 0;
}
