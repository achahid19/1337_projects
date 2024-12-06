#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

// Animal is an abstract class now
// since it contains at least 1 pure
// virtual function.
class Animal {
protected:
	std::string	type;

public:
	/* Canonical form */
	Animal( void );
	Animal( const Animal &other );
	const Animal& operator=( const Animal &other ) const;
	virtual ~Animal( void );

	/* Member functions */
	virtual void	makeSound( void ) const = 0;
	
	/* getter */
	const std::string&	getType( void ) const;
};

#endif /* ANIMAL_HPP */
