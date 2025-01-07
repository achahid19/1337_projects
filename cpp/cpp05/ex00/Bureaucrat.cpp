#include "Bureaucrat.hpp"

// Canonical form
Bureaucrat::Bureaucrat( void ) : name("bureaucrat_instance"), grade(150) {
	std::cout << GREEN << "[ Bureaucrat ]: Default constructor called";
	std::cout << RESET_COLOR << std::endl;
}

	// Constructor by parameter
Bureaucrat::Bureaucrat( const std::string& _name, int _grade )
			: name(_name), grade(NO_GRADE) {
	std::cout << GREEN << "[ Bureaucrat ]: constructor by parameter called";
	std::cout << RESET_COLOR << std::endl;
	try {
		if (_grade < 1) throw GradeTooHighException();
		else if (_grade > 150) throw GradeTooLowException();
		else grade = _grade;
	}
	catch (const std::string& err) {
		std::cout << RED << err;
		std::cout << RESET_COLOR << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.getName()) {
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
	try {
		if (grade == 1) throw GradeTooHighException();
		else grade--;
	}
	catch (const std::string& err) {
		std::cout << RED << err;
		std::cout << RESET_COLOR << std::endl;
	}
}

void	Bureaucrat::decrementGrade( void ) {
	try {
		if (grade == 150) throw GradeTooLowException();
		else grade++;
	}
	catch (const std::string& err) {
		std::cout << RED << err;
		std::cout << RESET_COLOR << std::endl;
	}
}

// Exceptions Bureaucrat's methods
const std::string	Bureaucrat::GradeTooHighException( void ) const {
	return this->getName() + "::GradeTooHighException";
}
const std::string	Bureaucrat::GradeTooLowException( void ) const {
	return this->getName() + "::GradeTooLowException";
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
