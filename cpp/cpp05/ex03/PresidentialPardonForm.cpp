#include "PresidentialPardonForm.hpp"

// Canonical Form
PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialForm", 25, 5),  _target("null") {
	/* std::cout << BLUE;
	std::cout << "[ PresidentialPardonForm ]: Default Constructor called";
	std::cout << RESET_COLOR << std::endl; */
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : 
					AForm::AForm("PresidentialForm", 25, 5), _target(target) {
	/* std::cout << BLUE;
	std::cout << "[ PresidentialPardonForm ]: Constructor by parameter called";
	std::cout << RESET_COLOR << std::endl; */
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : 
					AForm::AForm(copy), _target(copy._target) {
	/* std::cout << BLUE;
	std::cout << "[ PresidentialPardonForm ]: Copy constructor called";
	std::cout << RESET_COLOR << std::endl; */
	*this=(copy);
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy ) {
	/* std::cout << BLUE;
	std::cout << "[ PresidentialPardonForm ]: Assignment operator called";
	std::cout << RESET_COLOR << std::endl; */
	(void)copy;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	/* std::cout << BLUE;
	std::cout << "[ PresidentialPardonForm ]: Destructor called";
	std::cout << RESET_COLOR << std::endl; */
}

// methods
void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
    if (this->getIsSigned() == false)
		throw PresidentialPardonForm::UnsignedException();
	if (executor.getGrade() > this->getExecGrade())
        throw PresidentialPardonForm::GradeTooLowException();
	std::cout << BLUE << this->_target << " had been pardoned by Zaphod Beeblebrox";
	std::cout << RESET_COLOR << std::endl;
}

AForm*	PresidentialPardonForm::makePresidentialForm( const std::string &target ) {
	return (new PresidentialPardonForm(target));
}

// Exceptions
const char*	PresidentialPardonForm::UnsignedException::what() const throw() {
	return "Presidential Form: Trying to execute an unsigned form!";
}

const char*	PresidentialPardonForm::GradeTooHighException::what() const throw() {
	return "AForm::Presidential::GradeTooHighException";
}

const char*	PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return "AForm::Presidential::GradeTooLowException";
}
