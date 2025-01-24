#include "RobotomyRequestForm.hpp"

// Canonical Form
RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyForm", 72, 45),  _target("null") {
	/* std::cout << BLUE;
	std::cout << "[ RobotomyRequestForm ]: Default Constructor called";
	std::cout << RESET_COLOR << std::endl; */
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : 
					AForm::AForm("RobotomyForm", 72, 45), _target(target) {
	/* std::cout << BLUE;
	std::cout << "[ RobotomyRequestForm ]: Constructor by parameter called";
	std::cout << RESET_COLOR << std::endl; */
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : 
					AForm::AForm(copy), _target(copy._target) {
	/* std::cout << BLUE;
	std::cout << "[ RobotomyRequestForm ]: Copy constructor called";
	std::cout << RESET_COLOR << std::endl; */
	*this=(copy);
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy ) {
	/* std::cout << BLUE;
	std::cout << "[ RobotomyRequestForm ]: Assignment operator called";
	std::cout << RESET_COLOR << std::endl; */
	(void)copy;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	/* std::cout << BLUE;
	std::cout << "[ RobotomyRequestForm ]: Destructor called";
	std::cout << RESET_COLOR << std::endl; */
}

// helper function (DRY)
void	drillingNoise( Bureaucrat const& executor ) {
	std::cout << GREEN << executor.getName();
	std::cout << ": Vrrrrr Vrrrrr Vrrrrr..." << RESET_COLOR << std::endl, sleep(1);
}

// methods
void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (this->getIsSigned() == false) {
		drillingNoise(executor);
		std::cout << RED << "Robotomy failed!" << RESET_COLOR << std::endl;
		throw RobotomyRequestForm::UnsignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		drillingNoise(executor);
		std::cout << RED << "Robotomy failed!" << RESET_COLOR << std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	drillingNoise(executor);
	std::cout << GREEN << this->_target;
	std::cout << " had been robotomized succefully 50% of the time";
	std::cout << RESET_COLOR << std::endl;
}

// Exceptions
const char*	RobotomyRequestForm::UnsignedException::what() const throw() {
	return "Robotomy Form: Trying to execute an unsigned form!";
}

const char*	RobotomyRequestForm::GradeTooHighException::what() const throw() {
	return "AForm::Robotomy::GradeTooHighException";
}

const char*	RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return "AForm::Robotomy::GradeTooLowException";
}
