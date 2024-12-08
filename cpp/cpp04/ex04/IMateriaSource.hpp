#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#define LEARN_SLOTS 4

class AMateria;

class IMateriaSource {
public:
	virtual ~IMateriaSource( void ) {};
	virtual void learnMateria( AMateria* ) = 0;
	virtual AMateria* createMateria( std::string const &type ) = 0;
};

class MateriaSource : public IMateriaSource {
private:
	AMateria*	learnM[LEARN_SLOTS];
public:
	/* Canonical form */
	MateriaSource( void );
	MateriaSource( const MateriaSource& other );
	MateriaSource& operator=( const MateriaSource& other );
	~MateriaSource( void );
	/* Interface */
	void		learnMateria( AMateria* );
	AMateria*	createMateria( std::string const &type );
};


#endif /* IMATERIASOURCE_HPP */
