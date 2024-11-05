#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
		: ClapTrap(), __name__(ClapTrap::getName() + "_clap_trap")
{
	std::cout << "[ DiamondTrap ]: Default Constructor Called!" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
};

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), ScavTrap( other ), FragTrap( other ) {
	std::cout << "[ DiamondTrap ]: Copy constructor called" << std::endl;
	*this = other;
};

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &other ) {
	std::cout << "[ DiamondTrap ]: Copy Assignment called" << std::endl;
	if (this != &other) {
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
		__name__ = other.getName() + "_clap_trap";
	}
	return *this;
}

DiamondTrap::DiamondTrap( const std::string& name ) 
		: ClapTrap(), __name__(name + "_clap_trap")
{
	std::cout << "[ DiamondTrap ]: Constructor Called!" << std::endl;
	this->setName(name);
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
};

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "[ DiamondTrap ]: Destructor called!" << std::endl;
};

/* Member functions */

void	DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack(target);
};

void	DiamondTrap::whoAmI( void ) const {
	std::cout << "DiamondTrap's Name -> " << this->getName() << " and ";
	std::cout << "ClapTrap's Name -> " <<  __name__ << std::endl;
}
