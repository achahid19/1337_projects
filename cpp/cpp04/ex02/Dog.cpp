#include "Dog.hpp"

/* Canonical form */
Dog::Dog( void ) : Animal() {
    std::cout << RED;
    std::cout << "[ Dog ]: Default Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    type = "Dog";
    brain_ptr = new Brain();
}

Dog::Dog( const Dog& other ) {
    this->type = "Dog";
    this->brain_ptr = new Brain();
    
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
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < IDEAS; i++) {
        this->brain_ptr->setIdea(i, other.brain_ptr->getIdea(i));
    }
    return *this;
}

Dog::~Dog( void ) {
    std::cout << RED;
    std::cout << "[ Dog ]: Default Destructor called.";
    std::cout << RESET_COLOR << std::endl;
    delete brain_ptr;
}

void    Dog::makeSound( void ) const {
    std::cout << PURPLE;
    std::cout << "[ Dog ]: bark bark bark!";
    std::cout << RESET_COLOR << std::endl;
}

Brain*  Dog::getBrain( void ) const {
    return brain_ptr;
}
