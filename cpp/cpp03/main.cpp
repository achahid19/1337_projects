#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cassert>

inline void	pointsChecker(ClapTrap* clapTrap);

int	main( void ) {
	ScavTrap copy("test");
	ClapTrap *base = new ScavTrap(copy);

	std::cout << base->getName() << std::endl;
	std::cout << base->getEnergyPoints() << std::endl;
	//base->guardGate();
	delete base;
	return 0;
}

inline void	pointsChecker(ClapTrap* clapTrap) {
	std::cout << PURPLE;
	std::cout << "Energy: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << "Health: " << clapTrap->getHitPoints() << RESET_COLOR << std::endl;
	assert(clapTrap->getEnergyPoints() > 0);
	assert(clapTrap->getHitPoints() > 0);
}
