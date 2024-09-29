#include "Harl.hpp"

int	main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "[ USAGE ]: ./haltFtilter <Level>" << std::endl;
		return 1;
	}

	int		logLevel;
	Harl	levels(av[1], logLevel);
	
	levels.complain(logLevel);
	return 0;
}
