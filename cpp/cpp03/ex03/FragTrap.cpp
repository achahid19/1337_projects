#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "[ FragTrap ]: Constructor called!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap( other ) {
	std::cout << "[ FragTrap ]: Copy Consructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other ) {
	std::cout << "[ FragTrap ]: Copy assignment called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap( name ) {
	std::cout << "[ FragTrap ]: Constructor called!" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap( void ) {
	std::cout << "[ FragTrap ]: Destructor called!" << std::endl;
}

/* Member Function of FragTrap */

void	FragTrap::highFiveGuys( void ) {
	std::cout << "Positive high five request!" << std::endl;
}
