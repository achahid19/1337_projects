#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

#define __INT_MIN__ -2147483648
#define INT_OUT_OF_RANGE -2147483649
#define CHAR_NON_PRINTABLE -1

typedef struct s_conv_types {
	char	type;
	bool	conversion_status;
}	t_conv_types;

class ScalarConverter {
private:
	static char		c;
	static long		i;
	static double	d;
	static float	f;

	// prevent from initiating this static class
	// since the delete keyword to delete member funtions
	// was introduced in C++11
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter &copy );
	ScalarConverter& operator=( const ScalarConverter &copy );

public:
	static void	converter( const std::string &literal );
	static void	convertOthers( t_conv_types *ct, char type );
	static void	displaySystem( void );

	class	InvalidArgs : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class	ImpossibleConversion: public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

#endif /* SCALARCONVERTER_HPP */
