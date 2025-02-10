#include "Bureaucrat.hpp"

int main( void ) {
    try {
        Bureaucrat b1("b1", -1);
        std::cout << b1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }
    try {
        Bureaucrat b2("b2", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }
    try {
        Bureaucrat b3("b3", 10);
        b3.incrementGrade();
        b3.decrementGrade();
        std::cout << b3 << std::endl;
    }
    catch (std::exception& e) {
    std::cout << RED << e.what();
    std::cout << RESET_COLOR << std::endl;
    }

    return 0;
}

//#include <exception>

// exception testing.
//                  exception
//                      |
//           ------------------------
//           |          |           |
//      logic_error  bad_alloc   runtime_error
//           |
//      out_of_range

/* int main(void) {
    try {
        std::string name = "julien";

        std::cout << name.at(10) << std::endl;
    }
    // if an exception is thrown execution jump to catch block.
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        throw std::runtime_error("Problem encountred");
    }
    catch (std::exception &e) {
        std::cout << "Problem encountred" << std::endl;
    }
    std::cout << "program done" << std::endl;
} */
