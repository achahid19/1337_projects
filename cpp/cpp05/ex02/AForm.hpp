#ifndef AForm_HPP
#define AForm_HPP

#define DEFAULT_SIGN_G 100
#define DEFAULT_EXEC_G 90

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string 	_name;
	bool				_is_signed;
	const int			_grade_sign;
	const int			_grade_execute;

public:
	// Canonical AForm
	AForm( void );
	AForm( const std::string _name, int _grade_sign, int _grade_execute);
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	virtual ~AForm( void );

	// methods
	void				beSigned( Bureaucrat& bureaucrat );
	virtual void		execute( Bureaucrat const& executor ) const = 0;

	// Getter, Setter
	const std::string&  getName( void ) const;
	int      			getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	bool				getIsSigned( void ) const;

	// Exceptions handling
	class	GradeTooHighException : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

// overlaod insertion operator "<<"
std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif /* AForm_HPP */
