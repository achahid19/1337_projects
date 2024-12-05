#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
    Brain*  brain_ptr;
public:    
    /* Canonical form */
    Cat( void );
    Cat( const Cat &other );
    const Cat& operator=( const Cat &other ) const;
    ~Cat( void );

    /* Member functions */
    void    makeSound( void ) const;

    /* get brain object */
    Brain*  getBrain( void ) const;
};

#endif /* CAT_HPP */
