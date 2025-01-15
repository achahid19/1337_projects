#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include <cctype>
#include "ShruberryCreationForm.hpp"

#define FORMS 3

AForm*	makeShruberryForm( std::string target );
AForm*	makeRobotomyForm( std::string target );
AForm*	makePresidentialForm( std::string target );

typedef struct s_intern {
	const std::string form;
	AForm* (*func)(std::string target);
}	t_intern;

class Intern {
private:
	t_intern forms[FORMS] = {
		{"shruberry", &makeShruberryForm},
		{"robotomy", &makeRobotomyForm},
		{"presidential", &makePresidentialForm}
	};
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
