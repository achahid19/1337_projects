#include "Bureaucrat.hpp"

// Canonical form
Bureaucrat::Bureaucrat( void ) : name("bureaucrat_instance"), grade(DEFAULT_GRADE) {
	std::cout << GREEN << "[ Bureaucrat ]: Default constructor called";
	std::cout << RESET_COLOR << std::endl;
}

	// Constructor by parameter
Bureaucrat::Bureaucrat( const std::string& _name, int _grade )
			: name(_name), grade(NO_GRADE) {
	std::cout << GREEN << "[ Bureaucrat ]: constructor by parameter called";
	std::cout << RESET_COLOR << std::endl;
	if (_grade < 1) throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150) throw Bureaucrat::GradeTooLowException();
	else grade = _grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.getName() + "_copy") {
	std::cout << GREEN << "[ Bureaucrat ]: Copy Constructor called";
	std::cout << RESET_COLOR << std::endl;
	*this=(other);
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	std::cout << GREEN << "[ Bureaucrat ]: Copy Assignment called";
	std::cout << RESET_COLOR << std::endl;
	if (this != &other) {
		grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << GREEN << "[ Bureaucrat ]: Default destructor called";
	std::cout << RESET_COLOR << std::endl;
}

// methods
void	Bureaucrat::incrementGrade( void ) {
	grade--;
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade( void ) {
	grade++;
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

// Exceptions Bureaucrat's methods
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

// getters
const std::string&	Bureaucrat::getName( void ) const {
	return name;
}

int	Bureaucrat::getGrade( void ) const {
	return grade;
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return os;
}
