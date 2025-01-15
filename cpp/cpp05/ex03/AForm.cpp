#include "AForm.hpp"

// Canonical AForm
AForm::AForm( void ) : _name("AForm_instance"), _is_signed(false),
					_grade_sign(DEFAULT_SIGN_G), _grade_execute(DEFAULT_EXEC_G) {
	/* std::cout << PURPLE << "[ AForm ]: Default constructor called";
	std::cout << RESET_COLOR << std::endl; */
}

AForm::AForm( const std::string name, int grade_sign, int grade_execute) :
		_name(name), _is_signed(false),
		_grade_sign(grade_sign), _grade_execute(grade_execute) {
	/* std::cout << PURPLE << "[ AForm ]: Constructor by parameter called";
	std::cout << RESET_COLOR << std::endl; */
	if (grade_sign < 1 || grade_execute < 1) throw AForm::GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150) throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& other ) : _name(other.getName() + "_copy"),
		_grade_sign(other.getSignGrade()), _grade_execute(other.getExecGrade()) {
	/* std::cout << PURPLE << "[ AForm ]: Copy Constructor called";
	std::cout << RESET_COLOR << std::endl; */
	*this=(other);
}

AForm& AForm::operator=( const AForm& other ) {
	/* std::cout << PURPLE << "[ AForm ]: Copy Assignment called";
	std::cout << RESET_COLOR << std::endl; */
	if (this != &other) {
		_is_signed = other.getIsSigned();
	}
	return *this;
}

AForm::~AForm( void ) {
	/* std::cout << PURPLE << "[ AForm ]: Default destructor called";
	std::cout << RESET_COLOR << std::endl; */
}

// getters
const std::string& AForm::getName( void ) const {
	return _name;
}

int	AForm::getSignGrade( void ) const {
	return _grade_sign;
}

int	AForm::getExecGrade( void ) const {
	return _grade_execute;
}

bool	AForm::getIsSigned( void ) const {
	return _is_signed;
}

// Exceptions override what() method msg.
const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException";
}
const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException";
}

// methods
void	AForm::beSigned( Bureaucrat& Bureaucrat ) {
	if (Bureaucrat.getGrade() <= _grade_sign) _is_signed = true;
	else _is_signed = false, throw AForm::GradeTooLowException();
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << AForm.getName() << ", AForm's infos: " << std::endl;
	os << "-> grade_sign: " << AForm.getSignGrade() << std::endl;
	os << "-> grade_execute: " << AForm.getExecGrade() << std::endl;
	os << "-> is_signed: " << std::boolalpha << AForm.getIsSigned();
	return os;
}
