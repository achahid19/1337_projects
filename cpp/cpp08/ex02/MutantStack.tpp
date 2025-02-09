#include "MutantStack.hpp"

// Canonical form
template <typename T>
MutantStack<T>::MutantStack( void ) {};

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& copy ) : std::stack<T>(copy) {
	*this=(copy);
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=( const MutantStack& copy ) {
	(void)copy;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack( void ) {};

// Methods
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const {
	return this->c.end();
}
