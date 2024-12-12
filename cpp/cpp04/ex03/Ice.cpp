#include "Ice.hpp"
#include "utils.hpp"

/* Canonical form */

Ice::Ice( void ) : AMateria("ice") {
	print("[ Ice ]: Default Constructor Called", YELLOW);
}

Ice::Ice( const Ice& other ) : AMateria("ice") {
	print("[ Ice ]: Copy Constructor Called", YELLOW);
	*this=(other);
}

Ice&	Ice::operator=( const Ice& other ) {
	(void)other;
	print("[ Ice ]: Copy Assignment Called", YELLOW);
	return (*this);
}

Ice::~Ice( void ) {
	print("[ Ice ]: Destructor Called", YELLOW);
}

AMateria*	Ice::clone( void ) const {
	return new Ice(*this);
}

void    Ice::use( ICharacter& target ) {
    print("* shoots an ice bolt at " + target.getName() + " *", RESET_COLOR);
}
