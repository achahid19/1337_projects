#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

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
	virtual ~ClapTrap( void );
	
	/* member functions */
	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
	bool			pointsChecker( void );
	void			dumpEnergyPoints( void );

	/* Getters */
	int				getHitPoints( void ) const;
	int				getEnergyPoints( void ) const;
	int				getAttackDamage( void ) const;
	std::string		getName( void ) const;
	
	/* Setters */
	void			setName( const std::string& name );
	void			setHitPoints( int hitPoints );
	void			setEnergyPoints( int energyPoints );
	void			setAttackDamage( int attackDamage );
};

#endif /* CLAPTRAP_HPP */
