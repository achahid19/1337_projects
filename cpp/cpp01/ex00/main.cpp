#include "Zombie.h"

int main( void ) {
	Zombie* Mob = newZombie("Andy");

	Mob->annouce();
	randomChump("Otto");
	delete(Mob);
	std::cout << "-------------------" << std::endl;
	return (0);
}
