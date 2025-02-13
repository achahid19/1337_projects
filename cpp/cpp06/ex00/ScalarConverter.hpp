#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception> // exception handling
#include <cstdlib> // atoi, alol...
#include <limits.h> // INT_MIN, INT_MAX
#include <iomanip> // for std::fixed and std::setprecision

#define CHAR_NON_PRINTABLE -1
#define SET_D_PRECISION 1

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
	static bool		iOutOfRange;
	// prevent from initiating this static class
	// since the delete keyword to delete member funtions
	// was introduced in C++11
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter &copy );
	ScalarConverter& operator=( const ScalarConverter &copy );
	~ScalarConverter( void );

public:
	static void	converter( const std::string &literal );
	static void	convertOthers( t_conv_types *ct, char type );
	static void	displaySystem( void );

	class	ImpossibleConversion: public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

#endif /* SCALARCONVERTER_HPP */
