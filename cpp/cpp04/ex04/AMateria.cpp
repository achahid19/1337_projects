#include "AMateria.hpp"
#include "utils.hpp"

/* Canonical form */

AMateria::AMateria( void ) {
   print("[ Materia ]: Default Constructor Called", BLUE);
   type = "Materia";
}

AMateria::AMateria( const AMateria& other ) {
    print("[ Materia ]: Copy Constructor Called", BLUE);
    type = "Materia";
    *this=(other);
}

AMateria&  AMateria::operator=( const AMateria &other ) {
    print("[ Materia ]: Copy Assignment Called", BLUE);
    if (this != &other)
    {
        // make a deep copy if needed.
    }
    return *this;
}

AMateria::~AMateria( void ) {
    print("[ Materia ]: Destructor Called", BLUE);
}

/* Interface */

// test this constructor by parameter, is it
// working for derived classes.
AMateria::AMateria( std::string const& type ) : type(type) {
    print("[ Materia ]: Constructor by parameter called", BLUE);
}

std::string const&  AMateria::getType( void ) const {
    return (this->type);
}

void    AMateria::use( ICharacter& target ) {
 
}
