#ifndef FORM_HPP
#define FORM_HPP

#include "utils.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string 	name;
	bool				is_signed;
	int					grade_sign;
	int					grade_execute;
	// Exceptions handling
	const std::string	GradeTooHighException( void ) const;
	const std::string	GradeTooLowException( void ) const;
public:
	// Canonical form
	Form( void );
	Form( const std::string _name, int _grade_sign, int _grade_execute);
	Form( const std::string& name, int grade );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form( void );

	// methods
	void				beSigned( Bureaucrat& bureaucrat );

	// Getter, Setter
	const std::string&  getName( void ) const;
	int      			getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	bool				getIsSigned( void ) const;
};

// overlaod insertion operator "<<"
std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif /* FORM_HPP */
