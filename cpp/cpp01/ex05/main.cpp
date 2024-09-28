#include "Harl.hpp"

int	main( void ) {
	Harl	logs;

	logs.complain(DEBUG);
	logs.complain(WARNING);
	logs.complain(ERROR);
	logs.complain(INFO);
	return 0;
}
