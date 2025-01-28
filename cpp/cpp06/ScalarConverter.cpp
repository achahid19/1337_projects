#include "ScalarConverter.hpp"

// Define static members
// In C++, static data members need to be defined outside
// the class definition to allocate memory for them.
char	ScalarConverter::c;
long	ScalarConverter::i;
double	ScalarConverter::d;
float	ScalarConverter::f;

static char	getType( const std::string &literal );
static void	mutlipleSignCheck( const std::string &literal );

void	ScalarConverter::converter( const std::string &literal ) {
	t_conv_types	convertionTypes[] = {
		{'c', false},
		{'i', false},
		{'d', false},
		{'f', false},
	};
	// get the type: utility ?
		// 1. define the type of the literal to convert into it.
		// 2. throw exception the literal does not make any sense.
	char	type = getType(literal);

	for (size_t i = 0; i < 4; i++) {
		if (type == convertionTypes[i].type) {
			convertionTypes[i].conversion_status = true;
			// Convert to its actual type.
			switch(type) {
				case 'c':
						ScalarConverter::c = literal[0];
						convertOthers(convertionTypes, type); // Converts explicitly to the other types.
						break ;
				case 'i':
						mutlipleSignCheck(literal);
						ScalarConverter::i = std::atol(literal.c_str());
						if (ScalarConverter::i > __INT_MAX__ || ScalarConverter::i < __INT_MIN__)
							ScalarConverter::i = INT_OUT_OF_RANGE;
						convertOthers(convertionTypes, type);
						break ;
			}
		}
	}
	displaySystem();
}

const char*	ScalarConverter::InvalidArgs::what() const throw() {
	return "Invalid Args!";
}

const char*	ScalarConverter::ImpossibleConversion::what() const throw() {
	return "ImpossibleConversion";
}

static char	getType( const std::string &literal ) {
	bool	digit_status = false;
	bool	decimal_status = false;
	bool	float_status = false;

	if (literal.length() == 1) {
		if (std::isdigit(literal[0])) return 'i';
		return 'c';
	}
	// check if the literal is valid (General Check)
		// digits, decimal and 'f' for floats
		// check status to get the type
	for (size_t i = 0; literal[i]; i++) {
		if (std::isdigit(literal[i]) == false &&
			literal[i] != '.' &&
			literal[i] != 'f' &&
			literal[i] != '-' &&
			literal[i] != '+')
			throw ScalarConverter::ImpossibleConversion();
		if (std::isdigit(literal[i]) == true) digit_status = true;
		else if (literal[i] == '.') decimal_status = true;
		else if (literal[i] == 'f') float_status = true;
	}
	if (float_status == true) return 'f';
	else if (decimal_status == true) return 'd';
	return 'i';
}

void	ScalarConverter::convertOthers(t_conv_types *ct, char type ) {
	for (size_t i = 0; i < 4; i++) {
		if (ct[i].conversion_status == false) {
			switch(ct[i].type) {
				case 'c':
						if (type == 'i') {
							if (ScalarConverter::i < 33 || ScalarConverter::i > 126) {
								c = CHAR_NON_PRINTABLE;
								break ;
							}
							ScalarConverter::c = static_cast<char>(ScalarConverter::i);
						}
						break ;
				case 'i':
						if (type == 'c') ScalarConverter::i = static_cast<int>(ScalarConverter::c);
						break ;
			}
		}
	}
};

void	ScalarConverter::displaySystem( void ) {
	switch (c) {
		case CHAR_NON_PRINTABLE:
				std::cout << "char: Non displayable" << std::endl;
				break ;
		default:
				std::cout << "char: " << ScalarConverter::c << std::endl;
	}
	switch (i) {
		case INT_OUT_OF_RANGE:
				std::cout << "int: value out of range" << std::endl;
				break ;
		default:
				std::cout << "int: " << ScalarConverter::i << std::endl;
	}
};

static void	mutlipleSignCheck( const std::string &literal ) {
	for (size_t i = 0; literal[i]; i++) {
		if (isdigit(literal[i])) break ; // after the digit atol handles to extract the number;
		else if ((literal[i] == '+' || literal[i] == '-') &&
			(literal[i + 1] == '+' || literal[i + 1] == '-'))
			throw ScalarConverter::ImpossibleConversion();
	}
}
