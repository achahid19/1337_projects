#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {
    Intern  bob;
    Bureaucrat b1("b1", 5);
    PresidentialPardonForm p("no");
    AForm   *r;

    r = bob.makeForm("Presidential form request", "trump");
    try {
        r->execute(b1);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what();
        std::cout << std::endl;
    }

    try {
        b1.signForm(*r);
        b1.excecuteForm(*r);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what();
        std::cout << std::endl;
    }

    delete r;
    r = bob.makeForm("this time make a shruberry form", "home");
    try {
        r->execute(b1);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what();
        std::cout << std::endl;
    }

    try {
        b1.signForm(*r);
        b1.excecuteForm(*r);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what();
        std::cout << std::endl;
    }
    delete r;
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
