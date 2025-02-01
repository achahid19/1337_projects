#include "Serializer.hpp"

/* Canonical form */

Serializer::Serializer( void ) {};

Serializer::Serializer( const Serializer& copy ) { (*this)=copy; };

Serializer&	Serializer::operator=( const Serializer& copy ) {
	(void)copy;
	return *this;
};

Serializer::~Serializer( void ) {};

/* Methods */

uintptr_t	Serializer::serialize( data* ptr ) {
	uintptr_t	obj;

	// reinterpreting the pointer to an unsigned long.
	obj = reinterpret_cast<uintptr_t>(ptr);
	return obj;
}

data*	Serializer::deserialize( uintptr_t raw ) {
	data*	ptr;

	// reinterpreting this type of memory into something else.
	// uintptr_t to a pointer.
	ptr = reinterpret_cast<data*>(raw);
	return ptr;
}
