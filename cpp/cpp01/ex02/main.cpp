#include <iostream>

int	main( void ) {
	std::string		msg = "HI THIS IS BRAIN";
	std::string*	stringPTR = &msg;
	std::string		&stringREF = msg;

	std::cout << "Memory address of msg: " << &msg << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Value of msg variable: " << msg << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return 0;
};
