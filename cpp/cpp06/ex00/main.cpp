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
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
    return 0;
}
