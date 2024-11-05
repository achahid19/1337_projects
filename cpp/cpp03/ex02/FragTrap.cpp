#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "[ FragTrap ]: Constructor called!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap( other ) {
	std::cout << "[ FragTrap ]: Copy Consructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other ) {
	std::cout << "[ FragTrap ]: Copy assignment called" << std::endl;
	if (this != &other) {
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
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
