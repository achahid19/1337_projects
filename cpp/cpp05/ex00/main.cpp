#include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat b1;
    Bureaucrat b2 = b1;
    Bureaucrat b3;
    Bureaucrat b4("b4", 0);

    b3 = b2;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    b1.incrementGrade();
    b2.decrementGrade();

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    return 0;
}
