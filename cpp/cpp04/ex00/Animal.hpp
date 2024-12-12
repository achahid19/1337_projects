#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define RESET_COLOR "\033[0m"

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
	virtual void	makeSound( void ) const;

	/* getter */
	const std::string&	getType( void ) const;
};

/* class WrongAnimal {
public:
	void	makeSound( void ) const;
}; */

#endif /* ANIMAL_HPP */
