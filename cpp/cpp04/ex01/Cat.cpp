#include "Cat.hpp"

/* Canonical form */
Cat::Cat( void ) : Animal() {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Default Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    type = "Cat";
    brain_ptr = new Brain();
}

Cat::Cat( const Cat& other ) {
    this->type = "Cat";
    brain_ptr = new Brain();
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Copy Constructor called.";
    std::cout << RESET_COLOR << std::endl;
    *this = other;
}

const Cat& Cat::operator=( const Cat &other ) const {
    (void)other;
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Copy Assignment operator called.";
    std::cout << RESET_COLOR << std::endl;
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < IDEAS; i++) {
        this->brain_ptr->setIdea(i, other.brain_ptr->getIdea(i));
    }
    return *this;
}

Cat::~Cat( void ) {
    std::cout << YELLOW;
    std::cout << "[ Cat ]: Default Destructor called.";
    std::cout << RESET_COLOR << std::endl;
    delete brain_ptr;
}

void    Cat::makeSound( void ) const {
    std::cout << PURPLE;
    std::cout << "[ Cat ]: Meow Meow Meow!";
    std::cout << RESET_COLOR << std::endl;
}

Brain*  Cat::getBrain( void ) const {
    return brain_ptr;
}
