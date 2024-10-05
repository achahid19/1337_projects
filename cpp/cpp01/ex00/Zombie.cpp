#include "Zombie.h"

void    Zombie::annouce( void ) {
	std::cout << getName() << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
};

void    Zombie::setName( std::string newZombieName ) {
	name = newZombieName;
};

std::string	Zombie::getName() {
	return (name);
}

Zombie::~Zombie( void ) {
	std::cout << getName() << ": ";
	std::cout << "Destroyed" << std::endl;
};
