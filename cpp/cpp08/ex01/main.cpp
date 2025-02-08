#include "Span.hpp"

int	main( void ) {
	Span						obj(7);
	std::vector<unsigned int> 	values(1, 3);
	char						arr[6] = {
									100, 10, 39, 49, 48, 50
								};

	try {
		obj.fill(values.begin(), values.end());
		obj.fill(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::cout << "Container elements: ";
		for (size_t i = 0; i < obj.getSize(); i++) {
			std::cout << obj[i] << " ";
		}
		std::cout << std::endl;
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
