#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
	std::vector<int>			_v;
	std::vector<int>::iterator	_it;
	
public:
	// Canonical form
	Span( void );
	Span( unsigned int N );
	Span( Span& copy );
	Span&	operator=( Span& copy );
	~Span( void );

	// Mehotds
	void	addNumber( int	number );

	// Overload operator to access obj[index]
	int	operator[]( unsigned int i );

	// size getter
	size_t	getSize( void );
};

#endif // SPAN_HPP
