#include "ScalarConverter.hpp"

// Define static members
// In C++, static data members need to be defined outside
// the class definition to allocate memory for them.
char	ScalarConverter::c;
long	ScalarConverter::i;
double	ScalarConverter::d;
float	ScalarConverter::f;
bool	ScalarConverter::iOutOfRange = false;
bool	ScalarConverter::dOutOfRange = false;

static char	getType( const std::string &literal );
static void	signCheck( const std::string &literal );
static void	decimalPointCheck( const std::string &literal );

static long	convertToInt( const std::string &literal ) {
	long	i;
	
	signCheck(literal);
	i = std::atol(literal.c_str());
	std::cout << "i is: " << i << std::endl;
	return i;
}

static double	convertToDouble( const std::string &literal ) {
	double	d;
	
	signCheck(literal), decimalPointCheck(literal);
	d = std::strtod(literal.c_str(), NULL);
	return d;
}

/* static char	convertToChar( const std::string &literal ) {
	char	c;

	c = literal[0];
	return c;
} */

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
						ScalarConverter::i = convertToInt(literal);
						if (ScalarConverter::i > __INT_MAX__ || ScalarConverter::i < __INT_MIN__)
							ScalarConverter::iOutOfRange = true;
						convertOthers(convertionTypes, type);
						break ;
				case 'd':
						ScalarConverter::d = convertToDouble(literal);
						if (errno == ERANGE) ScalarConverter::dOutOfRange = true;
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
						switch (type) {
							case 'i':
									if (ScalarConverter::i < 33 || ScalarConverter::i > 126) {
										ScalarConverter::c = CHAR_NON_PRINTABLE;
										break ;
									}
									ScalarConverter::c = static_cast<char>(ScalarConverter::i);
									break ;
							case 'd':
									if (ScalarConverter::d < 33 || ScalarConverter::d > 126) {
										ScalarConverter::c = CHAR_NON_PRINTABLE;
										break ;
									}
									ScalarConverter::c = static_cast<char>(ScalarConverter::d);
									break ;
						}
				case 'i':
						switch (type) {
							case 'c':
									ScalarConverter::i = static_cast<char>(ScalarConverter::c);
									break ;
							case 'd':
									if (ScalarConverter::d > __INT_MAX__ || ScalarConverter::d < __INT_MIN__) {
										// converting double to int, must check if the value
										// is representable into an int data type
										ScalarConverter::iOutOfRange = true;
										break ;
									}
									ScalarConverter::i = static_cast<double>(ScalarConverter::d);
									break ;
						}
						break ;
				case 'd':
						switch (type) {
							case 'c':
									ScalarConverter::d = static_cast<char>(ScalarConverter::c);
									break ;
							case 'i':
									ScalarConverter::d = static_cast<int>(ScalarConverter::i);
									break ;
						}
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
	if (ScalarConverter::iOutOfRange == true)
		std::cout << "int: value out of range" << std::endl;
	else
		std::cout << "int: " << ScalarConverter::i << std::endl;
	std::cout << std::fixed << std::setprecision(SET_D_PRECISION);
	std::cout << "double: " << ScalarConverter::d << std::endl;
};

static void	signCheck( const std::string &literal ) {
	for (size_t i = 0; literal[i]; i++) {
		if ((literal[i] == '+' || literal[i] == '-') && i != 0)
			throw ScalarConverter::ImpossibleConversion();
	}
}

static void	decimalPointCheck( const std::string &literal ) {
	// the decimal points:
		// must not be duplicated
		// has a digit on his right
	int	decimalCounter = 0;

	for (size_t i = 0; literal[i]; i++) {
		if (decimalCounter > 1) throw ScalarConverter::ImpossibleConversion();
		if (literal[i] == '.') {
			if (isdigit(literal[i + 1]) == false) throw ScalarConverter::ImpossibleConversion();
			decimalCounter++;
		}
	}
}
