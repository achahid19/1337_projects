#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    std::cout << "--------" << std::endl;
    const   Animal j;
    std::cout << "--------" << std::endl;
    const   Cat     c;
    const   Cat     catCopy;
    std::cout << "--------" << std::endl;
    const Animal *x = new Animal(j);
    std::cout << "--------" << std::endl;
    const Animal *y = new Dog;
    std::cout << "--------" << std::endl;
    const Animal *z = new Cat(c);
    std::cout << "--------" << std::endl;
    catCopy = c;
    std::cout << "--------" << std::endl;

    std::cout << x->getType() << std::endl;
    std::cout << y->getType() << std::endl;
    std::cout << z->getType() << std::endl;

    x->makeSound();
    y->makeSound();
    z->makeSound();
    catCopy.makeSound();

    std::cout << "--------" << std::endl;
    delete x;
    std::cout << "--------" << std::endl;
    delete y;
    std::cout << "--------" << std::endl;
    delete z;
    std::cout << "--------" << std::endl;

   /*  std::cout << "------WrongAnimal & WrongCat--------" << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal;
    const WrongAnimal *wrongCat = new WrongCat;

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat; */

    return 0;
}
