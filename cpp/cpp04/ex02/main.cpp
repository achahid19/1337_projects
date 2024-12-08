#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    Animal* arr[IDEAS];

    for (size_t i = 0; i < IDEAS / 2; i++) {
        arr[i] = new Dog();
    }
    for (size_t i = IDEAS / 2; i < IDEAS; i++) {
        arr[i] = new Cat();
    }
    for (size_t i = 0; i < IDEAS; i++) {
        delete arr[i];
    }

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "            Deep Copy test         " << std::endl;
    std::cout << "-----------------------------------" << std::endl;


    const   Cat* cat = new Cat();
    const   Cat  catCopy;

    for (size_t i = 0; i < IDEAS; i++)
        cat->getBrain()->setIdea(i, "this is a cat");

    catCopy = *cat;

    std::cout << "-----------" << std::endl;

    for (size_t i = 0; i < IDEAS; i++)
        std::cout << catCopy.getBrain()->getIdea(i) << std::endl;
    
     for (size_t i = 0; i < IDEAS; i++)
        cat->getBrain()->setIdea(i, "this is a dog");
    
    for (size_t i = 0; i < IDEAS; i++)
        std::cout << catCopy.getBrain()->getIdea(i) << std::endl;
        
    delete cat;

    return 0;
}
