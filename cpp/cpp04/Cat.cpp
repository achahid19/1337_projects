#include "Cat.hpp"

/* Canonical form */
Cat::Cat( void ) : Animal() {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Default Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    type = "Cat";
}

Cat::Cat( const Cat& other ) : Cat() {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Copy Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    *this = other;
}

const Cat& Cat::operator=( const Cat &other ) const {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Copy Assignment operator called.";
    std::cout << RESET_COLOR << std::endl;
    return *this;
}

Cat::~Cat( void ) {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Default Destructor called.";
    std::cout << RESET_COLOR << std::endl;
}

void    Cat::makeSound( void ) const {
    std::cout << PURPLE;
    std::cout << "[ Cat ]: Meow Meow Meow!";
    std::cout << RESET_COLOR << std::endl;
}
