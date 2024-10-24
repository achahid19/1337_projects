#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//            CommonBaseClass
/*           /              \        */
//     	BaseClass1        BaseClass2
/*           \              /        */
//            Deriveted class

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	__name__;

public:
	DiamondTrap( void );
	DiamondTrap( const std::string& name );
	~DiamondTrap( void );
	
	/* Member fucntions */
	void	attack( std::string target );
	void	whoAmI( void ) const;
};

#endif /* DIAMONDTRA_HPP */
