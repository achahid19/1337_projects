#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_data {
	int			n;
	std::string	username;
}	data;

class	Serializer {
public:
	Serializer( void );
	Serializer( const Serializer& copy );
	Serializer& operator=( const Serializer& copy );
	~Serializer( void );

	// methods
	uintptr_t	serialize( data* ptr );
	data*		deserialize( uintptr_t raw );
};

#endif /* SERIALIZER_HPP */
