#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;
public:
	~Zombie( void );

	void				annouce( void );
	void				setName( const std::string newZombieName );
	const std::string	getName( void ) const;
	};

#endif /* ZOMBIE_HPP */
