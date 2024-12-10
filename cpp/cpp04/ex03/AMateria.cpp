#include "AMateria.hpp"
#include "utils.hpp"

/* Canonical form */

AMateria::AMateria( void ) {
   print("[ Materia ]: Default Constructor Called", BLUE);
   type = "Materia";
}

AMateria::AMateria( const AMateria& other ) {
    print("[ Materia ]: Copy Constructor Called", BLUE);
    *this=(other);
}

AMateria&  AMateria::operator=( const AMateria &other ) {
    (void)other;
    print("[ Materia ]: Copy Assignment Called", BLUE);
    return *this;
}

AMateria::~AMateria( void ) {
    print("[ Materia ]: Destructor Called", BLUE);
}

/* Interface */
AMateria::AMateria( std::string const& _type ) : type(_type) {
    print("[ Materia ]: Constructor by parameter called", BLUE);
}

std::string const&  AMateria::getType( void ) const {
    return (this->type);
}

void    AMateria::use( ICharacter& target ) {
    (void)target;
}
