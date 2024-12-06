#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    // Animal class, cannot be instantiated
    // Animal n; // will not work.
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

    const Cat* cat = new Cat();
    const Cat  testCopyCat;

    cat->getBrain()->setIdea(0, "This is a cat");
    testCopyCat = *cat;
    cat->getBrain()->setIdea(0, "This is a dogCat");

    std::cout << testCopyCat.getBrain()->getIdea(0) << std::endl;
    delete cat;
    return 0;
}
