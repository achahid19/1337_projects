#include "Bureaucrat.hpp"

// Canonical form
Bureaucrat::Bureaucrat( void ) : name("bureaucrat_instance"), grade(150) {
	print("[ Bureaucrat ]: Default constructor called", GREEN);
}

Bureaucrat::Bureaucrat( const std::string& name, unsigned int grade ) : name(name) {
	print("[ Bureaucrat ]: Parametric constructor called", GREEN);
	if (grade < 1) {
		try {
			throw GradeTooHighException();
		}
		catch (GradeTooHighException &e) {
			print(e.what(), RED);
		}
	}
	else if (grade > 150) {
		try {
			throw GradeTooLowException();
		}
		catch (GradeTooLowException &e) {
			print(e.what(), RED);
		}
	}
	else this->grade = grade;
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
	if (grade > 1) grade--;
	else print("Max grade reached!", RED);
}

void	Bureaucrat::decrementGrade( void ) {
	if (grade < 150) grade++;
	else print("Min grade reached", RED);
}

// getter
const std::string&	Bureaucrat::getName( void ) const {
	return name;
}

unsigned int	Bureaucrat::getGrade( void ) const {
	return grade;
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return os;
}
