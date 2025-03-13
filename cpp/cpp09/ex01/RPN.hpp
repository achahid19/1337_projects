#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
	std::string	_n;
	void	validRPN( void );
	bool	isOperand( const char c ) const;
	
public:
	// canonical form
	RPN( std::string n );
	void	rpn( void );
};

#endif /* RPN_HPP */
