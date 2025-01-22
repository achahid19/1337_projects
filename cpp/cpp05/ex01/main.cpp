#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
    Bureaucrat b1("b1", 100);
    Form       f1("f1", 110, 90);

    b1.signForm(f1);

    Bureaucrat b2("b2", 100);
    Form       f2("f2", 99, 80);

    b2.signForm(f2);

    try {
        Form    f3("f3", 0, 0);
    }
    catch (std::exception &e){
        std::cout << RED << e.what();
        std::cout << RESET_COLOR << std::endl;
    }

    try {
        Form    f4("f4", 100, 160);
    }
    catch (std::exception &e){
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
