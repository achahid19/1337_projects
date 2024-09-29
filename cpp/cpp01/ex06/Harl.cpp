#include "Harl.hpp"

Harl::Harl( std::string level, int &logLevel ) {
	if (level == "DEBUG") {
		logLevel = DEBUG;
	}
	else if (level == "INFO") {
		logLevel = INFO;
	}
	else if (level == "WARNING") {
		logLevel = WARNING;
	}
	else if (level == "ERROR") {
		logLevel = ERROR;
	}
	else
		logLevel = OFF;
};

void	Harl::complain( int logLevel ) {
	switch (logLevel) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about";
			std::cout << " insignificant problems ]" << std::endl;
			break ;
	}
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
}
