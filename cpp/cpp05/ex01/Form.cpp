#include "Form.hpp"

// Canonical form
Form::Form( void ) : name("Form_instance"), is_signed(false),
					grade_sign(DEFAULT_SIGN_G), grade_execute(DEFAULT_EXEC_G) {
	print("[ Form ]: Default constructor called", PURPLE);
}

Form::Form( const std::string _name, int _grade_sign, int _grade_execute) :
		name(_name), is_signed(false),
		grade_sign(DEFAULT_SIGN_G), grade_execute(DEFAULT_EXEC_G) {
	print("[ Form ]: constructor by parameter called", PURPLE);
	try {
		if (_grade_sign < 1 || _grade_execute < 1) throw GradeTooHighException();
		else if (_grade_sign > 150 || _grade_execute > 150) throw GradeTooLowException();
		else {
			grade_sign = _grade_sign;
			grade_execute = _grade_execute;
		}
	}
	catch (const std::string& err) {
		print(err, RED);
	}
}

Form::Form( const Form& other ) : name(other.getName()) {
	print("[ Form ]: Copy Constructor called", PURPLE);
	*this=(other);
}

Form& Form::operator=( const Form& other ) {
	print("[ Form ]: Copy Assignment called", PURPLE);
	if (this != &other) {
		grade_sign = other.getSignGrade();
		grade_execute = other.getExecGrade();
		is_signed = other.getIsSigned();
	}
	return *this;
}

Form::~Form( void ) {
	print("[ Form ]: Default destructor called", PURPLE);
}

// getters
const std::string& Form::getName( void ) const {
	return name;
}

int	Form::getSignGrade( void ) const {
	return grade_sign;
}

int	Form::getExecGrade( void ) const {
	return grade_execute;
}

bool	Form::getIsSigned( void ) const {
	return is_signed;
}

// Exceptions Form's methods
const std::string	Form::GradeTooHighException( void ) const {
	return this->getName() + ";Form::GradeTooHighException";
}
const std::string	Form::GradeTooLowException( void ) const {
	return this->getName() + ";Form::GradeTooLowException";
}

// methods
void	Form::beSigned( Bureaucrat& Bureaucrat ) {
	try {
		if (Bureaucrat.getGrade() <= grade_sign) is_signed = true;
		else throw GradeTooLowException();
	}
	catch (const std::string& err) {
		print(err, RED);
	}
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", form's infos: " << std::endl;
	os << "grade_sign: " << form.getSignGrade() << std::endl;
	os << "grade_execute: " << form.getExecGrade() << std::endl;
	os << "is_signed: " << std::boolalpha << form.getIsSigned();
	return os;
}
