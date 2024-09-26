#include "Weapon.hpp"

Weapon::Weapon( const std::string t ) {
	type = t;
};

std::string	Weapon::getType( void ) const {
	return (type);
};

void	Weapon::setType( const std::string t ) {
	type = t;
};
