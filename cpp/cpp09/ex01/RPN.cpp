#include "RPN.hpp"

// utility function.
static inline void trim(std::string& input);

// Canonical form
RPN::RPN (void ) {};
RPN::RPN( std::string n ) {
	::trim(n);
	_n = n;
}
RPN::RPN( RPN& copy ) { *this=(copy); }
RPN&	RPN::operator=( RPN& copy ) {
	this->_n = copy._n;
	return *this;
}
RPN::~RPN (void ) {};

// Methods
void	RPN::validRPN( void ) {
	if (_n.size() == 0) {
		throw std::runtime_error("Error: empty string!");
	}
	size_t found = _n.find_first_not_of("0123456789*+-/ ");

	if (found != std::string::npos || !isOperator(_n.at(_n.size() - 1))) {
		throw std::runtime_error("Error: invalid RPN");
	}
}

bool	RPN::isOperator( const char c ) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::rpn( void ) {
	std::stack<int>	s;

	validRPN();
	for (std::string::iterator it = _n.begin(); it != _n.end(); it++) {
		if (std::isspace(*it)) continue;
		if (isOperator(*it) == false) s.push(*it - 48);
		else {
			if (s.size() < 2)
				throw std::runtime_error("Error: Invalid operands!");
			int op2 = s.top(); s.pop();
			int op1 = s.top(); s.pop();

			switch (*it) {
				case '+':
						s.push(op1 + op2);
						break ;
				case '-':
						s.push(op1 - op2);
						break ;
				case '*':
						s.push(op1 * op2);
						break ;
				case '/':
						s.push(op1 / op2);
						break ;
			}
		}
	}
	if (s.size() != 1)
		throw std::runtime_error("Error: Invalid operators!");
	std::cout << s.top() << std::endl;
}

// Utility
static inline void trim(std::string& input) {
	// Trim trainling spaces
	std::string::iterator	ite = input.end() - 1;
	std::string::iterator	it = input.begin() - 1;

	while (ite != it && *ite == ' ') {
		input.erase(ite);
		ite--;
	}
	// Trim leading spaces
	size_t start = input.find_first_not_of(' ');
	if (start != std::string::npos) {
		input.erase(0, start);
	}
}
