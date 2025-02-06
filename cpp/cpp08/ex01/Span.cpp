#include "Span.hpp"

Span::Span( void ) : _it(_v.begin()) {
    std::cout << "[ Span ]: Default constructor called!" << std::endl;
}

Span::Span( unsigned int N ) : _v(std::vector<int>(N)), _it(_v.begin()) {
    std::cout << "[ Span ]: Parametrized constructor called!" << std::endl;
}

Span::Span( Span& copy ) {
	std::cout << "[ Span ]: Copy Constructor called!" << std::endl;
	*this=(copy);
}

Span&	Span::operator=( Span& copy ) {
	std::cout << "[ Span ]: Copy Assignment called!" << std::endl;
	if (this != &copy) {
		_v = std::vector<int>(copy.getSize());
		_it = _v.begin();
	}
	return *this;
}

Span::~Span( void ) {
    std::cout << "[ Span ]: Default destructor called!" << std::endl;
}

// Methods
void    Span::addNumber( int number ) {
    if (_it == _v.end())
        throw   std::runtime_error("Container out of space!");
    *_it = number;
	_it++;
}

// Operator Overload
int Span::operator[]( unsigned int i ) {
    if (i >= _v.size())
        throw   std::out_of_range("index out of range");
    return _v.at(i);
}

// Size getter

size_t	Span::getSize( void ) {
	return _v.size();
}