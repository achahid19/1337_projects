#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "utils.hpp"

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

	// Getter, Setter
	const std::string&  getName( void ) const;
	int      			getGrade( void ) const;
};

// overlaod insertion operator "<<"
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif /* BUREAUCRAT_H */
