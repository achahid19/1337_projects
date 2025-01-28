#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    
	try {
		if (ac != 2) throw ScalarConverter::InvalidArgs();
		ScalarConverter::converter(av[1]);
	}
	catch (const ScalarConverter::InvalidArgs &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const ScalarConverter::ImpossibleConversion &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}
