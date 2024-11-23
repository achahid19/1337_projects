#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    const Animal *x = new Animal;
    const Animal *y = new Dog;
    const Animal *z = new Cat;

    std::cout << x->getType() << std::endl;
    std::cout << y->getType() << std::endl;
    std::cout << z->getType() << std::endl;
    x->makeSound();
    y->makeSound();
    z->makeSound();
    delete x;
    delete y;
    delete z;

    return 0;
}
