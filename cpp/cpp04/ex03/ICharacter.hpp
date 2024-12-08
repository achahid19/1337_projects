#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"	

#define AMATERIA_SLOTS 4

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {};
	virtual std::string const& getName() const = 0;
	virtual void equip( AMateria* m ) = 0;
	virtual void unequip( int idx ) = 0;
	virtual void use( int idx, ICharacter& target ) = 0;
};

class Character : public ICharacter {
private:
	AMateria*		slots[AMATERIA_SLOTS];
	std::string		name;
public:
	/* Canonical form */
	Character( void );
	Character( const Character& other );
	Character& operator=( const Character& other );
	~Character( void );
	Character( std::string const &_name );

	std::string const& getName() const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};

#endif /* ICHARCTER_HPP */
