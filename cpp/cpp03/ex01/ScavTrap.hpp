#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap( const std::string& name );
	~ScavTrap( void );

	void	guardGate( void );
};

#endif /* SCAVTRAP_HPP */
