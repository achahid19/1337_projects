#ifndef HARL_HPP
#define HARL_HPP

#define DEBUG	"0"
#define INFO	"1"
#define WARNING "2"
#define ERROR	"3"
#define LOGS_LEVEL 4

#include <iostream>

class Harl;

typedef struct s_levels {
public:
	std::string level;
	void (Harl::*function)( void );
}	t_levels;

class Harl {
private:
	void debug( void );
	void info( void );
	void warning ( void );
	void error ( void );
	t_levels logs[LOGS_LEVEL];

public:
	Harl();

	void complain( std::string level );
};

#endif /* HARL_HPP */
