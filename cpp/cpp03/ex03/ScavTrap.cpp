#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "[ ScavTrap ]: Default Constructor called!" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
};

ScavTrap::ScavTrap( const ScavTrap &other) : ClapTrap( other ) {
	std::cout << "[ ScavTrap ]: Copy Constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "[ ScavTrap ]: Copy Assignment Called" << std::endl;
	if (this != &other) {
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

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
