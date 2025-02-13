#include "Serializer.hpp"

int	main( void ) {
	uintptr_t	i;
	Serializer	serializer;
	data		init_data;
	data*		data_to_check;
	
	init_data.n = 0;
	init_data.username = "xShahid";

	std::cout << "Data to Serialize: ";
	std::cout << init_data.n << init_data.username << std::endl;

	i = serializer.serialize(&init_data);
	// check i (uintptr_t type) returned from serializer
	std::cout << "i -> " << i << std::endl;

	// deserialize i to the initial data
	data_to_check = serializer.deserialize(i);
	// check the data
	std::cout << "Deserialization: ";
	std::cout << data_to_check->n << data_to_check->username << std::endl;
}
