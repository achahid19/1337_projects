#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // canonical form
    MutantStack( void ); 
    MutantStack( const MutantStack& copy );
    MutantStack&    operator=( const MutantStack& copy );
    ~MutantStack( void );

    // define iterator types
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    
    // methods
    iterator    begin( void );
    iterator    end( void );

    const_iterator    begin( void ) const;
    const_iterator    end( void ) const;
};

#include "MutantStack.tpp"

#endif  /* MUTANTSTACK_HPP */
