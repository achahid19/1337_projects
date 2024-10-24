#include "ScavTrap.hpp"

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name) {
	std::cout << "[ ScavTrap ]: Constructor called!" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
};

ScavTrap::~ScavTrap( void ) {
	std::cout << "[ ScavTrap ]: Destructor called!" << std::endl;
}

/* Member funtions of ScavTrap */
void	ScavTrap::guardGate( void ) {
	std::cout << "Guard keeper mode activeted!" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (pointsChecker() == false)
		return ;
	std::cout << "[ ScavTrap Attack ]: " << this->getName() << " attacks ";
	std::cout << target << std::endl;
	this->dumpEnergyPoints();
}
