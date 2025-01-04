#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const noexcept;
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const noexcept;
};

#endif // EXCEPTIONS_HPP
