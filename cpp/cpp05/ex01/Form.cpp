#include "Form.hpp"

// Canonical form
Form::Form( void ) : _name("Form_instance"), _is_signed(false),
					_grade_sign(DEFAULT_SIGN_G), _grade_execute(DEFAULT_EXEC_G) {
	/* std::cout << PURPLE << "[ Form ]: Default constructor called";
	std::cout << RESET_COLOR << std::endl; */
}

Form::Form( const std::string name, int grade_sign, int grade_execute) :
		_name(name), _is_signed(false),
		_grade_sign(grade_sign), _grade_execute(grade_execute) {
	/* std::cout << PURPLE << "[ Form ]: Constructor by parameter called";
	std::cout << RESET_COLOR << std::endl; */
	if (grade_sign < 1 || grade_execute < 1) throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150) throw Form::GradeTooLowException();
}

Form::Form( const Form& other ) : _name(other.getName() + "_copy"),
		_grade_sign(other.getSignGrade()), _grade_execute(other.getExecGrade()) {
	/* std::cout << PURPLE << "[ Form ]: Copy Constructor called";
	std::cout << RESET_COLOR << std::endl; */
	*this=(other);
}

Form& Form::operator=( const Form& other ) {
	/* std::cout << PURPLE << "[ Form ]: Copy Assignment called";
	std::cout << RESET_COLOR << std::endl; */
	if (this != &other) {
		_is_signed = other.getIsSigned();
	}
	return *this;
}

Form::~Form( void ) {
	/* std::cout << PURPLE << "[ Form ]: Default destructor called";
	std::cout << RESET_COLOR << std::endl; */
}

// getters
const std::string& Form::getName( void ) const {
	return _name;
}

int	Form::getSignGrade( void ) const {
	return _grade_sign;
}

int	Form::getExecGrade( void ) const {
	return _grade_execute;
}

bool	Form::getIsSigned( void ) const {
	return _is_signed;
}

// Exceptions override what() method msg.
const char*	Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException";
}
const char*	Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException";
}

// methods
void	Form::beSigned( Bureaucrat& Bureaucrat ) {
	if (Bureaucrat.getGrade() <= _grade_sign) _is_signed = true;
	else _is_signed = false, throw Form::GradeTooLowException();
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", form's infos: " << std::endl;
	os << "-> grade_sign: " << form.getSignGrade() << std::endl;
	os << "-> grade_execute: " << form.getExecGrade() << std::endl;
	os << "-> is_signed: " << std::boolalpha << form.getIsSigned();
	return os;
}
