#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
    Brain*  brain_ptr;
public:    
    /* Canonical form */
    Dog( void );
    Dog( const Dog &other );
    const Dog& operator=( const Dog &other ) const;
    ~Dog( void );

    /* Member functions */
    void    makeSound( void ) const;

    /* Get brain object */
    Brain*  getBrain( void ) const;
};

#endif /* DOG_HPP */
