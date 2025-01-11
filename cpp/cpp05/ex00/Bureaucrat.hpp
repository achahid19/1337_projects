#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

#define NO_GRADE -1
#define DEFAULT_GRADE 150

#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string 	_name;
	int					_grade;

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

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

// overlaod insertion operator "<<"
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif /* BUREAUCRAT_H */
