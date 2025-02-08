#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span {
private:
	std::vector<unsigned int>			_v;
	std::vector<unsigned int>::iterator	_it;
	
public:
	// Canonical form
	Span( void );
	Span( unsigned int N );
	Span( Span& copy );
	Span&	operator=( Span& copy );
	~Span( void );

	// Mehotds
	void			addNumber( int	number );
	unsigned int	shortestSpan( void );
	unsigned int	longestSpan( void );
	template <typename iterator>
	void			fill( iterator begin, iterator end ) {
		for ((void)begin; begin != end; begin++) addNumber(*begin);	
	}
	// Overload operator to access obj[index]
	unsigned int&	operator[]( unsigned int i );

	// size getter
	size_t	getSize( void );
};

#endif // SPAN_HPP
