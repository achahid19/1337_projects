#include "IMateriaSource.hpp"
#include "utils.hpp"

MateriaSource::MateriaSource( void ) {
    print("[ MateriaSource ]: Default Constructor Called", PURPLE);
    for (size_t i = 0; i < LEARN_SLOTS; i++)
        learnM[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
    print("[ MateriaSource ]: Copy Constructor Called", PURPLE);
    *this=(other);
}

MateriaSource&  MateriaSource::operator=( const MateriaSource& other ) {
    print("[ MateriaSource ]: Copy Assignment Called", PURPLE);
    if (this != &other) {
        for (size_t i = 0; i < LEARN_SLOTS; i++) {
            if (learnM[i] != NULL)
                delete learnM[i];
            learnM[i] = other.learnM[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource( void ) {
    print("[ MateriaSource ]: Destructor Called", PURPLE);
    for (size_t i = 0; i < LEARN_SLOTS; i++) {
        if (learnM[i] != NULL)
            delete learnM[i];
    }
}

/* Interface */
void    MateriaSource::learnMateria( AMateria* m ) {
    if (m == NULL)
        return ;
    size_t	i = 0;

	for (; i < LEARN_SLOTS; i++)
	{
		if (learnM[i] == NULL)
			break ;
	}
	if (i == LEARN_SLOTS)
	{
		print("No slot left to learn", RED);
		return ;
	}
	learnM[i] = m;
}

AMateria*   MateriaSource::createMateria( std::string const &type ) {
    size_t  i = 0;

    if (type != "ice" && type != "cure") {
        print("Unknown type!", RED);
        return NULL;
    }            
    for (; i < LEARN_SLOTS; i++) {
        if (learnM[i]->getType() == type)
            return learnM[i]->clone();
    }
    print("Didn't learnt this type yet!", PURPLE);
    return (NULL);
}
