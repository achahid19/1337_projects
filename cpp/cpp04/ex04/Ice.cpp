#include "Ice.hpp"
#include "utils.hpp"

/* Canonical form */

Ice::Ice( void ) : AMateria("ice") {
	print("[ Ice ]: Default Constructor Called", YELLOW);
}

Ice::Ice( const Ice& other ) {
	print("[ Ice ]: Copy Constructor Called", YELLOW);
	*this=(other);
}

Ice&	Ice::operator=( const Ice& other ) {
	print("[ Ice ]: Copy Assignment Called", YELLOW);
	if (this != &other)
	{
		type = "ice";
		// deep copy (use the clone member function)
	}
	return (*this);
}

Ice::~Ice( void ) {
	print("[ Ice ]: Destructor Called", YELLOW);
}

/* Interface */
AMateria*	Ice::clone( void ) const {
	// doing deep copy.
	return new Ice(*this);
}

void    Ice::use( ICharacter& target ) {
    std::string const targetName = target.getName();
    std::string const AMaterai_type = this->getType();

    AMaterai_type == "ice" ? 
            print("* shoots an ice bolt at " + targetName + " *", RESET_COLOR)
            : print("* heals " + targetName + "'s wounds *", RESET_COLOR);
}
