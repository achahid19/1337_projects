#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm::AForm("ShruberryForm", 145, 137),  _target("null") {
	/* std::cout << BLUE;
	std::cout << "[ ShruberryCreationForm ]: Default Constructor called";
	std::cout << RESET_COLOR << std::endl; */
}

ShruberryCreationForm::ShruberryCreationForm( std::string target ) : 
					AForm::AForm("ShruberryForm", 145, 137), _target(target) {
	/* std::cout << BLUE;
	std::cout << "[ ShruberryCreationForm ]: Constructor by parameter called";
	std::cout << RESET_COLOR << std::endl; */
}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm& copy ) : 
					AForm::AForm(copy), _target(copy._target) {
	/* std::cout << BLUE;
	std::cout << "[ ShruberryCreationForm ]: Copy constructor called";
	std::cout << RESET_COLOR << std::endl; */
	*this=(copy);
}

ShruberryCreationForm& ShruberryCreationForm::operator=( const ShruberryCreationForm& copy ) {
	/* std::cout << BLUE;
	std::cout << "[ ShruberryCreationForm ]: Assignment operator called";
	std::cout << RESET_COLOR << std::endl; */
	(void)copy;
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm( void ) {
	/* std::cout << BLUE;
	std::cout << "[ ShruberryCreationForm ]: Destructor called";
	std::cout << RESET_COLOR << std::endl; */
}

// methods
void	ShruberryCreationForm::execute( Bureaucrat const &executor ) const {
	if (this->getIsSigned() == false)
		throw ShruberryCreationForm::UnsignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw ShruberryCreationForm::GradeTooLowException();
	std::ofstream outfile;

	outfile.open((this->_target + "_shurberry").c_str());
	if (outfile.fail()) {
		std::cout << RED << "couldn't open file";
		std::cout << RESET_COLOR << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
}

// operator overload
std::ostream&	operator<<(std::ostream &os, const ShruberryCreationForm& form) {
	os << form.getName() << " form, signed: " << std::boolalpha;
	os << form.getIsSigned() << ", sign grade: ";
	os << form.getSignGrade() << ", execution grade: " << form.getExecGrade();

	return os;
}

// Exceptions
const char*	ShruberryCreationForm::UnsignedException::what() const throw() {
	return "Shruberry Form: Trying to execute an unsigned form!";
}

const char*	ShruberryCreationForm::GradeTooHighException::what() const throw() {
	return "AForm::Shruberry::GradeTooHighException";
}

const char*	ShruberryCreationForm::GradeTooLowException::what() const throw() {
	return "AForm::Shruberry::GradeTooLowException";
}
