#include "Zombie.h"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie*	newMobs = new Zombie [N];

	for (size_t index = 0; (int)index < N; index++) {
		newMobs[index].setName(name);
	}
	return (newMobs);
};
