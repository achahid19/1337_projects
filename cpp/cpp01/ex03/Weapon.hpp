#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon( const std::string t );

	const std::string&	getType( void ) const;
	void				setType( const std::string t );
};

#endif /* WEAPON_HPP */
