#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

#define MAX_HEALTH 10
#define MAX_ENERGY 10

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define RESET_COLOR "\033[0m"

class ClapTrap {
private:
	std::string	_name;
	int			_hitPoints; // Health of ClapTrap
	int			_energyPoints;
	int			_attackDamage;

public:
	/* Canonical form */
	ClapTrap( const std::string& name );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator=( const ClapTrap& other );
	~ClapTrap( void );
	
	/* member functions */
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	bool	pointsChecker( void );

	/* Getters */
	int		getHitPoints( void );
	int		getEnergyPoints( void );
};

#endif /* CLAPTRAP_HPP */
