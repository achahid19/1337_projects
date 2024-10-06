#include "Harl.hpp"

Harl::Harl() {
	logs[0].level = DEBUG;
	logs[0].function = &Harl::debug;
	logs[1].level = INFO;
	logs[1].function = &Harl::info;
	logs[2].level = WARNING;
	logs[2].function = &Harl::warning;
	logs[3].level = ERROR;
	logs[3].function = &Harl::error;
};

void	Harl::complain( std::string level ) {
	for (size_t index = 0; index < LOGS_LEVEL; index++) {
		if (level == this->logs[index].level) {
			(this->*logs[index].function)();
				break;
		}
	}
}

void	Harl::debug( void ) {
	std::cout << "[ Debug ]" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ Info ]" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ Warning ]" << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ Error ]" << std::endl;
}
