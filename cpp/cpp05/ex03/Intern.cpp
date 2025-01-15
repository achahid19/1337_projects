#include "Intern.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// canonical form
Intern::Intern( void ) {
	std::cout << YELLOW << "[ Intern ]: Default Constructor called!";
	std::cout << RESET_COLOR << std::endl;
}

Intern::Intern( const Intern& copy ) {
	std::cout << YELLOW << "[ Intern ]: Copy Constructor called!";
	std::cout << RESET_COLOR << std::endl;
	*this=(copy);
}

Intern& Intern::operator=( const Intern& copy ) {
	std::cout << YELLOW << "[ Intern ]: Copy Assignment called!";
	std::cout << RESET_COLOR << std::endl;
	return *this;
}

Intern::~Intern( void ) {
	std::cout << YELLOW << "[ Intern ]: Default destructor called!";
	std::cout << RESET_COLOR << std::endl;
}

// methods

AForm*	makeShruberryForm( std::string target ) {
	return (new ShruberryCreationForm(target));
}

AForm*	makeRobotomyForm( std::string target ) {
	return (new RobotomyRequestForm(target));
}

AForm*	makePresidentialForm( std::string target ) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, const std::string target) {
	int	position, formStatus = false;

	for (size_t i = 0; i < formName.length(); i++)
		formName[i] = tolower(formName[i]);
	std::cout << "Check: " << formName << std::endl;
	for (size_t i = 0; i < FORMS; i++) {
		position = formName.find(forms[i].form);
		if (position != std::string::npos) {
			std::cout << "Creating the form" << std::endl;
			std::cout << "Intern creates " << forms[i].form;
			std::cout << " form" << std::endl;
			return ((forms[i].func)(target));
		}
	}
	std::cout << "The requested form does not exist!" << std::endl;
	return NULL;
}
