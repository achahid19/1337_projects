#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // canonical form
    MutantStack( void ) {}; 
    MutantStack( const MutantStack& copy ) : std::stack<T>(copy) {*this=(copy);};
    MutantStack&    operator=( const MutantStack& copy ) {
        (void)copy;
        return *this;
    };
    ~MutantStack( void ) {};

    // define iterator types
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    
    // methods
    iterator    begin( void ) {
        return this->c.begin();
    }

    iterator    end( void ) {
        return this->c.end();
    }

    const_iterator    begin( void ) const {
        return this->c.begin();
    }

    const_iterator    end( void ) const {
        return this->c.end();
    }
};


#endif  /* MUTANTSTACK_HPP */
