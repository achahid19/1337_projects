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

unsigned int	Span::shortestSpan( void ) {
	std::vector<int>	_vCopy;
	
	if (_v.size() <= 1) throw std::runtime_error("Unsufficient elements on the span!");
	_vCopy.assign(_v.begin(), _v.end()); // copy content of _v to _vCopy and overwrite
	std::sort(_vCopy.begin(), _vCopy.end());
	// remove duplicates from _vCopy
	_vCopy.erase(std::unique(_vCopy.begin(), _vCopy.end()), _vCopy.end());
	std::vector<int>::iterator it = _vCopy.begin();
	if (*it == 0 && _vCopy.size() > 2) it++;
	return std::abs(*it - *(it + 1));
}

unsigned int	Span::longestSpan( void ) {
	if (_v.size() <= 1) throw std::runtime_error("Unsufficient elements on the span!");

	size_t	maxValue = *std::max_element(_v.begin(), _v.end());
	size_t	minValue = *std::min_element(_v.begin(), _v.end());

	return maxValue - minValue;
}

// Operator Overload
int& Span::operator[]( unsigned int i ) {
    if (i >= _v.size())
        throw   std::out_of_range("index out of range");
    return _v.at(i);
}

// Size getter

size_t	Span::getSize( void ) {
	return _v.size();
}