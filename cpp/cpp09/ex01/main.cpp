#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
		return(std::cerr << "Error: invalid number of arguments" << std::endl, 0);

	RPN	obj(av[1]);

	try {
		obj.rpn();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
