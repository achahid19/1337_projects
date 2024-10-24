#include "ClapTrap.hpp"
#include <cassert>

inline void	pointsChecker(ClapTrap* clapTrap);

int	main( void ) {
	ClapTrap clapTrap("itks");

	clapTrap.takeDamage(5);
	pointsChecker(&clapTrap);
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.takeDamage(3);
	clapTrap.attack("jule");
	pointsChecker(&clapTrap);
	clapTrap.attack("jule");
	pointsChecker(&clapTrap);
	clapTrap.beRepaired(3);
	pointsChecker(&clapTrap);
	return 0;
}

inline void	pointsChecker(ClapTrap* clapTrap) {
	std::cout << PURPLE;
	std::cout << "Energy: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << "Health: " << clapTrap->getHitPoints() << RESET_COLOR << std::endl;
	assert(clapTrap->getEnergyPoints() > 0);
	assert(clapTrap->getHitPoints() > 0);
}
