#include "Zombie.h"

void	Zombie::annouce( void ) {
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
};

void	Zombie::setName( const std::string newZombieName ) {
	name = newZombieName;
};

const std::string	Zombie::getName() const {
	return (name);
}

Zombie::~Zombie( void ) {
	std::cout << getName() << ": ";
	std::cout << "Destroyed" << std::endl;
};
