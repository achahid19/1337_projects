#include "RPN.hpp"

RPN::RPN( std::string n ) : _n(n) {}

void	RPN::validRPN( void ) {
	if (_n.size() == 0) {
		throw std::runtime_error("Error: empty string!");
	}
	size_t found = _n.find_first_not_of("0123456789*+-/ ");

	if (found != std::string::npos || !isOperand(_n.at(_n.size() - 1))) {
		throw std::runtime_error("Error: invalid RPN");
	}
}

bool	RPN::isOperand( const char c ) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::rpn( void ) {
	std::stack<int>	s;

	// run checks for invalid rpn.
	validRPN();

	// loop over the string, push into s until size is 2
	for (std::string::iterator it = _n.begin(); it != _n.end(); it++) {
		if (isspace(*it) == true) continue;
		else if (isOperand(*it) == false) {
			s.push(*it - 48);
		}
		else if (s.size() == 2) {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();

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
			}
		}
		else {
			throw std::runtime_error("Error: RPN calculation");
		}
	}
	std::cout << "result: " << s.top() << std::endl;
}