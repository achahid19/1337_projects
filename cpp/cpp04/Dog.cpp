#include "Dog.hpp"

/* Canonical form */
Dog::Dog( void ) : Animal() {
    std::cout << RED;
    std::cout << "[ Dog ]: Default Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    type = "Dog";
}

Dog::Dog( const Dog& other ) {
    this->type = "Dog";
    std::cout << RED;
    std::cout << "[ Dog ]: Copy Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    *this = other;
}

const Dog& Dog::operator=( const Dog &other ) const {
    (void)other;
    std::cout << RED;
    std::cout << "[ Dog ]: Copy Assignment operator called.";
    std::cout << RESET_COLOR << std::endl;
    return *this;
}

Dog::~Dog( void ) {
    std::cout << RED;
    std::cout << "[ Dog ]: Default Destructor called.";
    std::cout << RESET_COLOR << std::endl;
}

void    Dog::makeSound( void ) const {
    std::cout << PURPLE;
    std::cout << "[ Dog ]: bark bark bark!";
    std::cout << RESET_COLOR << std::endl;
}
