#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define TREE "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"

class ShruberryCreationForm : public AForm {
private:
    std::string         _target;
public:
    // Canocial form
    ShruberryCreationForm( void );
    ShruberryCreationForm( std::string target );
    ShruberryCreationForm( const ShruberryCreationForm& copy );
    ShruberryCreationForm& operator=( const ShruberryCreationForm& copy );
    ~ShruberryCreationForm( void );

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

std::ostream&   operator<<(std::ostream &os, const ShruberryCreationForm& form );

#endif /* SHRUBERRYCREATIONFORM_HPP */
