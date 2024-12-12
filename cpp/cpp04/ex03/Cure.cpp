#include "Cure.hpp"
#include "utils.hpp"

/* Canonical form */

Cure::Cure( void ) : AMateria("cure") {
	print("[ Cure ]: Default Constructor Called", YELLOW);
}

Cure::Cure( const Cure& other ) : AMateria("cure") {
	print("[ Cure ]: Copy Constructor Called", YELLOW);
	*this=(other);
}

Cure&	Cure::operator=( const Cure& other ) {
	(void)other;
	print("[ Cure ]: Copy Assignment Called", YELLOW);
	return (*this);
}

Cure::~Cure( void ) {
	print("[ Cure ]: Destructor Called", YELLOW);
}

AMateria*	Cure::clone( void ) const {
	return new Cure(*this);
}

void    Cure::use( ICharacter& target ) {
	print("* heals " + target.getName() + "'s wounds *", RESET_COLOR);
}
