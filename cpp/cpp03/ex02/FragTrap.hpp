#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap( const std::string& name );
	~FragTrap( void );

	/* Member functions */
	void	highFiveGuys( void );
};

#endif /* FRAGTRA_HPP */