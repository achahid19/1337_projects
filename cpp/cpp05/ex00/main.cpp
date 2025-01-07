#include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat b1("b1", 150);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 150);
    Bureaucrat b4("b4", 10);
    Bureaucrat b5("b5", 151);
    Bureaucrat b6("b6", -1);

    b3 = b2;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;
    std::cout << b6 << std::endl;

    b1.incrementGrade();
    b2.decrementGrade();
    b2.decrementGrade();
    b2.incrementGrade();

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

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
