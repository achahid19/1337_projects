#include "Intern.hpp"
#include "AForm.hpp"

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
	(void)copy;
	return *this;
}

Intern::~Intern( void ) {
	std::cout << YELLOW << "[ Intern ]: Default destructor called!";
	std::cout << RESET_COLOR << std::endl;
}

// methods
AForm*	Intern::makeForm(std::string formName, const std::string target) {
	int	position;
	std::string formsNames[] = {
				"shruberry",
				"robotomy",
				"presidential"
				};
	AForm*	(*f[])(const std::string &target) = {
				ShruberryCreationForm::makeShruberryForm,
				RobotomyRequestForm::makeRobotomyForm,
				PresidentialPardonForm::makePresidentialForm
				};

	for (size_t i = 0; i < formName.length(); i++)
		formName[i] = std::tolower(formName[i]);
	std::cout << "-> Check: " << formName << std::endl;
	for (size_t i = 0; i < FORMS; i++) {
		position = formName.find(formsNames[i]);
		if ((size_t)position != std::string::npos) {
			std::cout << "-> Creating the form" << std::endl;
			std::cout << "-> Intern creates " << formsNames[i];
			std::cout << " form" << std::endl;
			return ((f[i])(target));
		}
	}
	std::cout << "The requested form does not exist!" << std::endl;
	return NULL;
}
