#include "utils.hpp"

int main( void ) {

IMateriaSource* src = new MateriaSource();

src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");
AMateria* tmp;

tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);

delete bob;
delete me;
delete src;

std::cout << "--------------- More tests ------------------" << std::endl;
src = new MateriaSource();

src->learnMateria(new Ice());

ICharacter* C = new Character("grass");
AMateria    *ptr = src->createMateria("cure");

C->equip(ptr); // passing NULL Materia
C->unequip(3); // unequip none existing index.

ptr = src->createMateria("ice");

C->equip(ptr);
C->use(0, *C);

//C->unequip(0); // must be freed manually

delete src;
delete C;
//delete ptr;

return 0;
}
