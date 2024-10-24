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

void	ScavTrap::guardGate( void ) {
	std::cout << "Guard keeper mode activeted!" << std::endl;
}
