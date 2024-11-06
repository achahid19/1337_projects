#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
		: ClapTrap(), __name__(ClapTrap::_name + "_clap_trap")
{
	std::cout << "[ DiamondTrap ]: Default Constructor Called!" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), ScavTrap( other ), FragTrap( other ) {
	std::cout << "[ DiamondTrap ]: Copy constructor called" << std::endl;
	*this = other;
};

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &other ) {
	std::cout << "[ DiamondTrap ]: Copy Assignment called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		__name__ = other._name + "_clap_trap";
	}
	return *this;
}

DiamondTrap::DiamondTrap( const std::string& name ) 
		: ClapTrap(), __name__(name + "_clap_trap")
{
	std::cout << "[ DiamondTrap ]: Constructor Called!" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "[ DiamondTrap ]: Destructor called!" << std::endl;
};

/* Member functions */

void	DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack(target);
};

void	DiamondTrap::whoAmI( void ) const {
	std::cout << "DiamondTrap's Name -> " << this->_name << " and ";
	std::cout << "ClapTrap's Name -> " <<  this->__name__ << std::endl;
}
