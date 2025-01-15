#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"
#include <unistd.h>

class PresidentialPardonForm : public AForm {
private:
    std::string         _target;
public:
    // Canocial form
    PresidentialPardonForm( void );
    PresidentialPardonForm( std::string target );
    PresidentialPardonForm( const PresidentialPardonForm& copy );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& copy );
    ~PresidentialPardonForm( void );

    // methods
    void	execute( Bureaucrat const &executor ) const;

    // Excepitons
    class   UnsignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class	GradeTooHighException : public std::exception {
        public:
		    virtual const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
        public:
		    virtual const char*	what() const throw();
	};
};

#endif /* PRESIDENTIAL_PARDON_FORM */
