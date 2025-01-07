#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#define NO_GRADE -1

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

#define DEFAULT_GRADE 150

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string 	name;
	int					grade;
	// Exceptions handling
	const std::string	GradeTooHighException( void ) const;
	const std::string	GradeTooLowException( void ) const;
public:
	// Canonical form
	Bureaucrat( void );
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	// methods
	void  				incrementGrade( void );
	void  				decrementGrade( void );
	void				signForm( Form& form );

	// Getter, Setter
	const std::string&  getName( void ) const;
	int      			getGrade( void ) const;
};

// overlaod insertion operator "<<"
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif /* BUREAUCRAT_H */
