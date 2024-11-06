#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "[ ScavTrap ]: Constructor called!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
};

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name) {
	std::cout << "[ ScavTrap ]: Constructor called!" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap( other ) {
	std::cout << "[ ScavTrap ]: Copy Constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
	std::cout << "[ ScavTrap ]: Copy Assignement called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

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
	std::cout << "[ ScavTrap Attack ]: " << this->_name << " attacks ";
	std::cout << target << std::endl;
	this->_energyPoints--;
}
