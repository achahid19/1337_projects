#ifndef HARL_HPP
#define HARL_HPP

#define DEBUG	0
#define INFO	1
#define WARNING	2
#define ERROR	3
#define OFF		4

#include <iostream>

class Harl {
private:
	void		debug( void );
	void		info( void );
	void		warning ( void );
	void		error ( void );
	std::string	_level;
	int			_logLevel;

public:
	Harl( const std::string level );

	void complain( void );
	int	getLogLevel( void ) const;
};

#endif /* HARL_HPP */
