#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;
public:
	~Zombie( void );

	void		annouce( void );
	void		setName( std::string newZombieName );
	std::string	getName( void );
	};

#endif /* ZOMBIE_HPP */
