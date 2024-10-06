#include "Zombie.h"

int	main( void ) {
	Zombie* Mob = newZombie("Andy");
	Zombie* newMobs = zombieHorde(ZOMBIE_HORDE, "common");

	Mob->annouce();
	randomChump("Otto");
	delete(Mob);
	std::cout << "-------------------" << std::endl;
	for (size_t index = 0; index < ZOMBIE_HORDE; index++)  {
		newMobs[index].annouce();
	};
	delete [] newMobs;
	return (0);
}
