#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include <cctype>
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORMS 3

class Intern {
public:
	// canonical form
	Intern( void );
	Intern( const Intern& copy );
	Intern& operator=( const Intern& copy );
	~Intern( void );

	// methods
	AForm*	makeForm(std::string formName, const std::string target);
};

#endif /* INTERN_HPP */
