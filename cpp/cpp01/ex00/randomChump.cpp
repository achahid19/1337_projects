#include "Zombie.h"

void    randomChump( std::string name ) {
	Zombie  newMob;

	newMob.setName(name);
	newMob.annouce();
};
