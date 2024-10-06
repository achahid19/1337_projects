#include "Harl.hpp"

Harl::Harl( std::string level ) {
	this->_level = level;
};

int Harl::getLogLevel( void ) const {
	if (this->_level == "DEBUG") {
		return(DEBUG);
	}
	else if (this->_level == "INFO") {
		return(INFO);
	}
	else if (this->_level == "WARNING") {
		return(WARNING);
	}
	else if (this->_level == "ERROR") {
		return(ERROR);
	}
	return(OFF);
}

void	Harl::complain() {
	_logLevel = getLogLevel();

	switch (_logLevel) {
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
