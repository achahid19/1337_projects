#include "Base.hpp"
#include "utils.hpp"

int	main( void ) {
	Base*	obj;

	obj = generate();
	identity(obj); 
	delete obj;

	return 0;
}