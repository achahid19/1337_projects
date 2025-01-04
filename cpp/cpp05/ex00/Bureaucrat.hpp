#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "utils.hpp"

class Bureaucrat {
private:
	const std::string  name;
	unsigned int       grade;
public:
	// Canonical form
	Bureaucrat( void );
	Bureaucrat( const std::string& name, unsigned int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	// methods
	void  incrementGrade( void );
	void  decrementGrade( void );

	// overlaod operator "<<"
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

	// Getter, Setter
	const std::string&  getName( void ) const;
	unsigned int      	getGrade( void ) const;
};

#endif /* BUREAUCRAT_H */
