#include "utils.hpp"
#include "IMateriaSource.hpp"

int main( void ) {

/* AMateria* ice = new Ice();
AMateria* cure = new Cure();
ICharacter* c = new Character();
ICharacter* b = new Character("test");


print(ice->getType(), RED);
print(cure->getType(), RED);

c->equip(ice);
c->equip(cure);
c->equip(ice);
c->equip(cure);
//c->equip(cure);
c->use(0, *b);
c->use(1, *b);
c->use(2, *b);
c->use(3, *b);
c->unequip(0);
c->equip(cure);
c->use(0, *c); */

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

return 0;
}
