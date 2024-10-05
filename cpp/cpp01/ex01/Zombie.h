#include <iostream>
#include "Zombie.hpp"

#ifndef ZOMBIE_HORDE
#define ZOMBIE_HORDE 2
#endif /* ZOMBIE_HORDE */

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
Zombie*	zombieHorde( int N, std::string name );
