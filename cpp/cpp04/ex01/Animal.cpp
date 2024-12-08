#include "Animal.hpp"

Animal::Animal( void ) : type("animalDefaultName") {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Default Constructor called.";
	std::cout << RESET_COLOR << std::endl;
}

Animal::Animal( const Animal &other ) : type("animalDefaultName") {
	std::cout << GREEN;
	std::cout << "[ Animal ]: Copy Constructor Called.";
	std::cout << RESET_COLOR << std::endl;
	*this = other;
}

const Animal&	Animal::operator=( const Animal &other ) const {
	(void)other;
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
	std::cout << "[ Animal ]: No Sound!";
	std::cout << RESET_COLOR << std::endl;
}

/* Getter */
const std::string&	Animal::getType( void ) const {
	return (type);
}
