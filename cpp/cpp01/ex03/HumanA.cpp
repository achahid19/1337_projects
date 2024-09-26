#include "HumanA.hpp"

HumanA::HumanA( const std::string n, Weapon &w ) {
	name = n;
	weapon = &w;
};

void	HumanA::attack( void ) {
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon->getType() << std::endl;
}
