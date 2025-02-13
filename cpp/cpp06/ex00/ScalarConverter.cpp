#include "ScalarConverter.hpp"

char	ScalarConverter::c;
long	ScalarConverter::i;
double	ScalarConverter::d;
float	ScalarConverter::f;
bool	ScalarConverter::iOutOfRange = false;

static char		getType( const std::string &literal );
static long		convertToInt( const std::string &literal );
static double	convertToDouble( const std::string &literal );
static float	convertToFloat( const std::string &literal );
static void		signCheck( const std::string &literal );
static void		decimalPointCheck( const std::string &literal );
static void		floatCharCheck( const std::string &literal );

void	ScalarConverter::converter( const std::string &literal ) {
	t_conv_types	convertionTypes[] = {
		{'c', false},
		{'i', false},
		{'d', false},
		{'f', false},
	};
	char	type = getType(literal);

	for (size_t i = 0; i < 4; i++) {
		if (type == convertionTypes[i].type) {
			convertionTypes[i].conversion_status = true;
			// Convert to its actual type.
			switch(type) {
				case 'c':
						ScalarConverter::c = literal[0];
						convertOthers(convertionTypes, type);
						break ;
				case 'i':
						ScalarConverter::i = convertToInt(literal);
						if (ScalarConverter::i > INT_MAX || ScalarConverter::i < INT_MIN)
							ScalarConverter::iOutOfRange = true;
						convertOthers(convertionTypes, type);
						break ;
				case 'd':
						ScalarConverter::d = convertToDouble(literal);
						convertOthers(convertionTypes, type);
						break ;
				case 'f':
						ScalarConverter::f = convertToFloat(literal);
						convertOthers(convertionTypes, type);
						break ;
			}
		}
	}
	displaySystem();
}

static char	getType( const std::string &literal ) {
	bool	decimal_status = false;
	bool	float_status = false;

	if (literal.length() == 1) {
		if (std::isdigit(literal[0])) return 'i';
		return 'c';
	}
	for (size_t i = 0; literal[i]; i++) {
		if (std::isdigit(literal[i]) == false &&
			literal[i] != '.' &&
			literal[i] != 'f' &&
			literal[i] != '-' &&
			literal[i] != '+')
			throw std::runtime_error("Invalid argument!");
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
			ct[i].conversion_status = true;
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
							case 'f':
									if (ScalarConverter::f < 33 || ScalarConverter::f > 126) {
										ScalarConverter::c = CHAR_NON_PRINTABLE;
										break ;
									}
									ScalarConverter::c = static_cast<char>(ScalarConverter::f);
									break ;
						}
				case 'i':
						switch (type) {
							case 'c':
									ScalarConverter::i = static_cast<int>(ScalarConverter::c);
									break ;
							case 'd':
									if (ScalarConverter::d > INT_MAX
										|| ScalarConverter::d < INT_MIN) {
										ScalarConverter::iOutOfRange = true;
										break ;
									}
									ScalarConverter::i = static_cast<int>(ScalarConverter::d);
									break ;
							case 'f':
									if (ScalarConverter::f > (float)INT_MAX
										|| ScalarConverter::f < (float)INT_MIN) {
										ScalarConverter::iOutOfRange = true;
										break ;
									}
									ScalarConverter::i = static_cast<int>(ScalarConverter::f);
									break ;
						}
						break ;
				case 'd':
						switch (type) {
							case 'c':
									ScalarConverter::d = static_cast<double>(ScalarConverter::c);
									break ;
							case 'i':
									ScalarConverter::d = static_cast<double>(ScalarConverter::i);
									break ;
							case 'f':
									ScalarConverter::d = static_cast<double>(ScalarConverter::f);
									break ;
						}
						break ;
				case 'f':
						switch (type) {
							case 'c':
									ScalarConverter::f = static_cast<float>(ScalarConverter::c);
							case 'i':
									ScalarConverter::f = static_cast<float>(ScalarConverter::i);
							case 'd':
									ScalarConverter::f = static_cast<float>(ScalarConverter::d);
						}
			}
		}
	}
};

void	ScalarConverter::displaySystem( void ) {
	switch (c) {
		case CHAR_NON_PRINTABLE:
		case ' ':
				std::cout << "char: Non displayable" << std::endl;
				break ;
		default:
				std::cout << "char: " << ScalarConverter::c << std::endl;
	}
	switch (static_cast<int>(ScalarConverter::iOutOfRange)) {
		case true:
				std::cout << "int: value out of range" << std::endl;
				break ;
		default:
				std::cout << "int: " << ScalarConverter::i << std::endl;
	}
	std::cout << std::fixed << std::setprecision(SET_D_PRECISION);
	std::cout << "float: " << ScalarConverter::f << "f" << std::endl;
	std::cout << "double: " << ScalarConverter::d << std::endl;
};

static long		convertToInt( const std::string &literal ) {
	long	i;
	
	signCheck(literal);
	i = std::atol(literal.c_str());
	return i;
}

static double	convertToDouble( const std::string &literal ) {
	double	d;
	
	signCheck(literal);
	decimalPointCheck(literal);
	d = std::strtod(literal.c_str(), NULL);

    return d;
}

static float	convertToFloat( const std::string &literal ) {
	float	f;

	signCheck(literal);
	decimalPointCheck(literal);
	floatCharCheck(literal);
	f = std::strtof(literal.c_str(), NULL);

	return f;
}

static void	signCheck( const std::string &literal ) {
	for (size_t i = 0; literal[i]; i++) {
		if ((literal[i] == '+' || literal[i] == '-') && i != 0)
			throw ScalarConverter::ImpossibleConversion();
	}
}

static void	decimalPointCheck( const std::string &literal ) {
	int	decimalCounter = 0;

	for (size_t i = 0; literal[i]; i++) {
		if (decimalCounter > 1) throw ScalarConverter::ImpossibleConversion();
		if (literal[i] == '.') {
			if (isdigit(literal[i + 1]) == false)
				throw ScalarConverter::ImpossibleConversion();
			decimalCounter++;
		}
	}
}

static void	floatCharCheck( const std::string &literal ) {
	bool	decimalP = false;

	for (size_t i = 0; literal[i]; i++) {
		if (literal[i] == 'f') {
			if (isdigit(literal[i - 1]) == false || literal[i + 1] != '\0')
				throw ScalarConverter::ImpossibleConversion();
		}
		else if (literal[i] == '.') decimalP = true;
	}
	if (decimalP == false) throw ScalarConverter::ImpossibleConversion();
}

const char*	ScalarConverter::ImpossibleConversion::what() const throw() {
	return "ImpossibleConversion";
}
