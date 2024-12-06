#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"

#define IDEAS 100

class Brain {
private:
    std::string ideas[IDEAS];
public:
    /* Canonical form */
    Brain( void );
    Brain( const Brain& other );
    const Brain& operator=( const Brain& other );
    ~Brain( void );

    void                setIdea( size_t index, const std::string& idea );
    const std::string&  getIdea( size_t index ) const;
};

#endif /* BRAIN_HPP */
