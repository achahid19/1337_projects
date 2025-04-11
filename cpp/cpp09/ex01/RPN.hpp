#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
	std::string	_n;
	void	validRPN( void );
	bool	isOperator( const char c ) const;
	
public:
	// canonical form
	RPN( void );
	RPN( std::string n );
	RPN( RPN& copy );
	RPN&	operator=( RPN& copy );
	~RPN( void );

	void	rpn( void );
};

#endif /* RPN_HPP */
