#include "ClapTrap.hpp"

void	pointsChecker(ClapTrap* clapTrap);

int	main( void ) {
	ClapTrap clapTrap("itks");

	clapTrap.takeDamage(5);
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	clapTrap.takeDamage(5);
	clapTrap.attack("jule");
	clapTrap.attack("jule");
	pointsChecker(&clapTrap);
	
	pointsChecker(&clapTrap);
	clapTrap.beRepaired(10);
	return 0;
}

void	pointsChecker(ClapTrap* clapTrap) {
	std::cout << PURPLE;
	std::cout << "Energy: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << "Health: " << clapTrap->getHitPoints() << RESET_COLOR << std::endl;
}
