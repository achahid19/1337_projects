#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	BitcoinExchange	btc;

	if (ac != 2){ 
		return (std::cerr << "Error: input file is missing" << std::endl, 0);
	}
	try {
		btc.executeRequest(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
