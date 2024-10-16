#include "ClapTrap.hpp"

/* Canonical Form */
ClapTrap::ClapTrap( const std::string& name ) {
	std::cout << GREEN;
	std::cout << "[ClapTrap]: Constructor Called!" << RESET_COLOR << std::endl;
	_name = name;
	_hitPoints = MAX_HEALTH;
	_energyPoints = MAX_ENERGY;
	_attackDamage = 0;
};

ClapTrap::ClapTrap( const ClapTrap& other ) {
	std::cout << GREEN;
	std::cout << "[ClapTrap]: Copy Constructor Called!" << RESET_COLOR << std::endl;
	*this=(other);
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
	std::cout << GREEN;
	std::cout << "[ClapTrap]: Copy Assignment Called!" << RESET_COLOR << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << GREEN;
	std::cout << "[ClapTrap]: Destructor Called!" << RESET_COLOR << std::endl;
}

/* Member Functions */
void	ClapTrap::attack( const std::string& target ) {
	if (pointsChecker() == false)
		return ;
	std::cout << "ClapTrap " << _name << " attacks ";
	std::cout << target << ", Causing " << _attackDamage;
	std::cout << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (pointsChecker() == false)
		return ;
	std::cout << "clapTrap took " << amount << " damage hit points" << std::endl;
	_hitPoints -= amount;
	_hitPoints < 0 ? _hitPoints = 0 : _hitPoints = _hitPoints;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (pointsChecker() == false)
		return ;
	std::cout << "Repairing health for " << amount;
	std::cout << "hit points" << std::endl;
	_hitPoints += amount;
	_hitPoints > MAX_HEALTH ? _hitPoints = MAX_HEALTH : _hitPoints = _hitPoints;
	_energyPoints--;
}

bool	ClapTrap::pointsChecker( void ) {
	if (_energyPoints == 0) {
		std::cout << RED << "[ No energy points left! ]" << RESET_COLOR << std::endl;
		return false;
	}
	if (_hitPoints == 0) {
		std::cout << RED << "[ Low health ]" << RESET_COLOR << std::endl;
		return false;
	}
	return true;
}

int		ClapTrap::getHitPoints( void ) {
	return _hitPoints;
}

int		ClapTrap::getEnergyPoints( void ) {
	return _energyPoints;
}