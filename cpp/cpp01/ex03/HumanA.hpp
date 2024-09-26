#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon		*weapon;
	
public:
	HumanA( const std::string n, Weapon &w );

	void	attack( void );
};

#endif /* HUMANA_HPP */
