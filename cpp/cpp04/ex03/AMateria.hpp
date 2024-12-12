#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	/* Attributes to add on */
	std::string	type;

public:
	/* Canonical form */
	AMateria( void );
	AMateria( const AMateria& other );
	AMateria& operator=( const AMateria &other );
	virtual ~AMateria( void );

	AMateria( std::string const& _type );

	std::string const& getType( void ) const; //returns the materia's type.

	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );
};

#endif /* AMATERIA_HPP */
