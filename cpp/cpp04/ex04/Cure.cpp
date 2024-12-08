#include "Cure.hpp"
#include "utils.hpp"

/* Canonical form */

Cure::Cure( void ) : AMateria("cure") {
	print("[ Cure ]: Default Constructor Called", YELLOW);
}

Cure::Cure( const Cure& other ) {
	print("[ Cure ]: Copy Constructor Called", YELLOW);
	*this=(other);
}

Cure&	Cure::operator=( const Cure& other ) {
	print("[ Cure ]: Copy Assignment Called", YELLOW);
	if (this != &other)
	{
		type = "Cure";
		// deep copy (use the clone member function)
	}
	return (*this);
}

Cure::~Cure( void ) {
	print("[ Cure ]: Destructor Called", YELLOW);
}

/* Interface */
AMateria*	Cure::clone( void ) const {
	// doing deep copy.
	return new Cure(*this);
}

void    Cure::use( ICharacter& target ) {
    std::string const targetName = target.getName();
    std::string const AMaterai_type = this->getType();

    AMaterai_type == "ice" ? 
            print("* shoots an ice bolt at " + targetName + " *", RESET_COLOR)
            : print("* heals " + targetName + "'s wounds *", RESET_COLOR);
}
