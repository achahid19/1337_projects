#include "Span.hpp"

Span::Span( void ) : _N(0) {
    //std::cout << "[ Span ]: Default constructor called!" << std::endl;
}

Span::Span( unsigned int N ) : _N(N) {
    //std::cout << "[ Span ]: Parametrized constructor called!" << std::endl;
}

Span::Span( Span& copy ) {
	//std::cout << "[ Span ]: Copy Constructor called!" << std::endl;
	*this=(copy);
}

Span&	Span::operator=( Span& copy ) {
	//std::cout << "[ Span ]: Copy Assignment called!" << std::endl;
	if (this != &copy) {
		this->fill(copy.begin(), copy.end());
	}
	return *this;
}

Span::~Span( void ) {
    //std::cout << "[ Span ]: Default destructor called!" << std::endl;
}

// Methods
void    Span::addNumber( int number ) {
	if (_v.size() == _N || _N == 0)
		throw   std::runtime_error("Container out of space!");
    _v.push_back(number);
}

unsigned int	Span::shortestSpan( void ) {
	if (_v.size() <= 1)
		throw std::runtime_error("Unsufficient elements on the span!");
	
	std::vector<unsigned int>::const_iterator 	i = _v.begin();
	std::vector<unsigned int>::const_iterator 	j;
	int											shortSpan = INT_MAX;

	for ((void)i; i != _v.end(); i++) {
		for (j = i + 1; j != _v.end(); j++) {
			if (std::abs(long(*j) - long(*i)) < shortSpan) {
				shortSpan = std::abs(long(*j) - long(*i));
			}
		}
	}
	return shortSpan;
}

unsigned int	Span::longestSpan( void ) {
	if (_v.size() <= 1)
		throw std::runtime_error("Unsufficient elements on the span!");

	size_t	maxValue = *std::max_element(_v.begin(), _v.end());
	size_t	minValue = *std::min_element(_v.begin(), _v.end());

	return maxValue - minValue;
}

void	Span::generateUniqueRandomNums( 
		std::set<int> &nums,
		unsigned int	approximativeGenNums,
		unsigned int	maxRange
	) {
		srand(static_cast<unsigned int>(time(0)));

		for (
				size_t i = 0;
				i < approximativeGenNums + (approximativeGenNums / 8); 
				i++
			) {
			nums.insert(rand() % maxRange + 1);
		}
}

std::vector<unsigned int>::const_iterator	Span::begin( void ) {
	return _v.begin();
}

std::vector<unsigned int>::const_iterator	Span::end( void ) {
	return _v.end();
}
