#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	/* Canonical form */
	Ice( void );
	Ice( const Ice& other );
	Ice& operator=( const Ice& other );
	~Ice( void );
	
	AMateria* clone( void ) const;
	void use( ICharacter& target );
};

#endif /* ICE_HPP */
