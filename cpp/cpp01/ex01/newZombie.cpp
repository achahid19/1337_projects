#include "Zombie.h"

Zombie*	newZombie( std::string name ) {
	Zombie* newMob = new Zombie;

	newMob->setName(name);
	return (newMob);
};
