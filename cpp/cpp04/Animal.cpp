#include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Default Constructor called.";
	std::cout << RESET_COLOR << std::endl;
	type = "animalDefaultName";
}

Animal::Animal( const Animal &other ) : Animal() {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Copy Constructor Called.";
	std::cout << RESET_COLOR << std::endl;
	*this = other;
}

const Animal&	Animal::operator=( const Animal &other ) const {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Copy Assignment operator Called.";
	std::cout << RESET_COLOR << std::endl;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Default Destructor Called.";
	std::cout << RESET_COLOR << std::endl;
}

/* Member functions */
void	Animal::makeSound( void ) const {
	std::cout << PURPLE;
	std::cout << "[ Animal ]: WOOOOOOO!";
	std::cout << RESET_COLOR << std::endl;
}

/* Getter */
const std::string&	Animal::getType( void ) const {
	return (type);
}
