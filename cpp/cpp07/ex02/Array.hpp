#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array { // Class template
private:
	T			*data;
	unsigned int _size;
	
public:
	/* Canonical form */
	Array( void );
	Array( unsigned int n );
	Array( const Array& copy );
	const Array& operator=( const Array& copy );
	~Array( void );

	/* Methods */
	unsigned int	size( void ) const;

	/* operator overload */
	T&	operator[]( int index ) const;
};

#include "Array.tpp"

#endif /* ARRAY_HPP */
