#include "Bureaucrat.hpp"

// Exceptions Bureaucrat's methods
const std::string	Bureaucrat::GradeTooHighException( void ) const {
	return this->getName() + ";Bureaucrat::GradeTooHighException";
}
const std::string	Bureaucrat::GradeTooLowException( void ) const {
	return this->getName() + ";Bureaucrat::GradeTooLowException";
}

// Canonical form
Bureaucrat::Bureaucrat( void ) : name("bureaucrat_instance"), grade(150) {
	print("[ Bureaucrat ]: Default constructor called", GREEN);
}

// Constructor by parameter
Bureaucrat::Bureaucrat( const std::string& _name, int _grade )
			: name(_name), grade(NO_GRADE) {
	print("[ Bureaucrat ]: constructor by parameter called", GREEN);
	try {
		if (_grade < 1) throw GradeTooHighException();
		else if (_grade > 150) throw GradeTooLowException();
		else grade = _grade;
	}
	catch (const std::string& err) {
		print(err, RED);
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.getName()) {
	print("[ Bureaucrat ]: Copy Constructor called", GREEN);
	*this=(other);
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	print("[ Bureaucrat ]: Copy Assignment called", GREEN);
	if (this != &other) {
		grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	print("[ Bureaucrat ]: Default destructor called", GREEN);
}

// methods
void	Bureaucrat::incrementGrade( void ) {
	try {
		if (grade == 1) throw GradeTooHighException();
		else grade--;
	}
	catch (const std::string& err) {
		print(err, RED);
	}
}

void	Bureaucrat::decrementGrade( void ) {
	try {
		if (grade == 150) throw GradeTooLowException();
		else grade++;
	}
	catch (const std::string& err) {
		print(err, RED);
	}
}

void	Bureaucrat::signForm( Form& form ) {
	form.beSigned(*this);
	if (form.getIsSigned() == true)
		print(this->getName() + " signed " + form.getName(), YELLOW);
	else 
		print(this->getName() + " couldn't sign " + form.getName()
			+ " because grade's too low ", RED);
}

// getter
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
