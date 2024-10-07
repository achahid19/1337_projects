#include "Harl.hpp"

Harl::Harl( std::string level ) {
	if (level == "DEBUG") {
		_logLevel = DEBUG;
	}
	else if (level == "INFO") {
		_logLevel = INFO;
	}
	else if (level == "WARNING") {
		_logLevel = WARNING;
	}
	else if (level == "ERROR") {
		_logLevel = ERROR;
	}
	else
		_logLevel = OFF;
};


void	Harl::complain() {
	switch (_logLevel) {
		case DEBUG:
			debug();
			// intentional fallthrough
		case INFO:
			info();
			// intentional fallthrough
		case WARNING:
			warning();
			// intentional fallthrough
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
