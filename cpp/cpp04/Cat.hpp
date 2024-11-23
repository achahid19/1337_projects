#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:    
    /* Canonical form */
    Cat( void );
    Cat( const Cat &other );
    const Cat& operator=( const Cat &other ) const;
    ~Cat( void );

    /* Member functions */
    void    makeSound( void ) const;
};

#endif /* CAT_HPP */
