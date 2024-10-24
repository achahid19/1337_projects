#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "[ FragTrap ]: Constructor called!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap( name ) {
	std::cout << "[ FragTrap ]: Constructor called!" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap( void ) {
	std::cout << "[ FragTrap ]: Destructor called!" << std::endl;
}

/* Member Function of FragTrap */

void	FragTrap::highFiveGuys( void ) {
	std::cout << "Positive high five request!" << std::endl;
}
