#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <ctime>
#include <cstdlib>


class Span {
private:
	std::vector<unsigned int>	_v;
	size_t						_N;
	
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
	void			generateUniqueRandomNums(
		std::set<int> &set, 
		unsigned int approximativeGenNums,
		unsigned int maxRange
	);
	
	// vector iterators - READ-ONLY
	std::vector<unsigned int>::const_iterator	begin( void );
	std::vector<unsigned int>::const_iterator	end( void );
};

#endif // SPAN_HPP
