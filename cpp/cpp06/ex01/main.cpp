#include "Serializer.hpp"

int	main( void ) {
	uintptr_t	obj;
	Serializer	serializer;
	data		init_data;
	data*		data_to_check;
	
	init_data.n = 0;
	init_data.username = "xShahid";

	std::cout << "Data to Serialize: ";
	std::cout << init_data.n << init_data.username << std::endl;

	obj = serializer.serialize(&init_data);
	// check the obj (uintptr_t type) returned from serializer
	std::cout << "objj -> " << obj << std::endl;

	// deserialize the obj to the initial data
	data_to_check = serializer.deserialize(obj);
	// check the data
	std::cout << "Deserialized obj: ";
	std::cout << data_to_check->n << data_to_check->username << std::endl;
}
