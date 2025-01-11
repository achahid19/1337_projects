#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    std::cout << "----------- Shruberry Form Unit tests ------------" << std::endl;
    try {
        Bureaucrat b1("b1", 100);
        ShruberryCreationForm s("home");

        b1.signForm(s);
        b1.excecuteForm(s);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b2("b2", 140);
        ShruberryCreationForm s("home2");

        b2.signForm(s);
        b2.excecuteForm(s);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b3("b3", 150);
        ShruberryCreationForm s("home3");
        
        b3.signForm(s);
        b3.excecuteForm(s);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b4("b4", 150);
        ShruberryCreationForm s("home3");
        
        b4.excecuteForm(s);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    std::cout << "----------- Shruberry Form Unit tests ------------" << std::endl;
    std::cout << "----------- Robotomy Form Unit tests ------------" << std::endl;   
    try {
        Bureaucrat b1("b1", 50);
        RobotomyRequestForm r("alien");

        b1.signForm(r);
        b1.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b2("b2", 80);
        RobotomyRequestForm r("alien");
    
        b2.excecuteForm(r);
        b2.signForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b3("b3", 80);
        RobotomyRequestForm r("alien");
        
        b3.signForm(r);
        b3.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b4("b4", 30);
        RobotomyRequestForm r("alien");
        
        b4.signForm(r);
        b4.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }
    std::cout << "----------- Robotomy Form Unit tests ------------" << std::endl;
    std::cout << "----------- Presidential Form Unit tests ------------" << std::endl;
    try {
        Bureaucrat b1("b1", 50);
        PresidentialPardonForm r("alien");

        b1.signForm(r);
        b1.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b2("b2", 80);
        PresidentialPardonForm r("alien");
    
        b2.excecuteForm(r);
        b2.signForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b3("b3", 80);
        PresidentialPardonForm r("alien");
        
        b3.signForm(r);
        b3.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Bureaucrat b4("b4", 2);
        PresidentialPardonForm r("alien");
        
        b4.signForm(r);
        b4.excecuteForm(r);
    }
    catch (std::exception& e) {
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }
    std::cout << "----------- Presidential Form Unit tests ------------" << std::endl;

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
