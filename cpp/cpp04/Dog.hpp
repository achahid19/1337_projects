#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:    
    /* Canonical form */
    Dog( void );
    Dog( const Dog &other );
    const Dog& operator=( const Dog &other ) const;
    ~Dog( void );

    /* Member functions */
    void    makeSound( void ) const;
};

#endif /* DOG_HPP */
