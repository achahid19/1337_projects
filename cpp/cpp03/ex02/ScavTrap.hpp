#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap( void );
	ScavTrap( const ScavTrap &other);
	ScavTrap& operator=( const ScavTrap &other);
	ScavTrap( const std::string& name );
	~ScavTrap( void );

	void	guardGate( void );
	void	attack( const std::string& target );
};

#endif /* SCAVTRAP_HPP */
