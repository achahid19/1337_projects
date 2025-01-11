#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <unistd.h>

class RobotomyRequestForm : public AForm {
private:
    std::string         _target;

public:
    // Canocial form
    RobotomyRequestForm( void );
    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( const RobotomyRequestForm& copy );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& copy );
    ~RobotomyRequestForm( void );

    // methods
    void	execute( Bureaucrat const &executor ) const;

    // Excepitons
    class   UnsignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class	GradeTooHighException : public std::exception {
		virtual const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		virtual const char*	what() const throw();
	};
};

std::ostream&   operator<<(std::ostream &os, const RobotomyRequestForm& form );

#endif /* ROBOTOMY_REQUEST_FORM_HPP */
