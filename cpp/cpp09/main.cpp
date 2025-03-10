#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	BitcoinExchange	btc;

	if (ac != 2){ 
		return (std::cerr << "Error: input file is missing" << std::endl, 0);
	}
	try {
		btc.loadRequestFile(av[1]);
		btc.displayRequest();
	}
	catch(std::logic_error &e) {
		std::cout << "Error: Invalid date => " << e.what() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
