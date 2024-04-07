#include "philo.h"

void	print_error(const char *error);

/**
 * print_error
*/
void	print_error(const char *error)
{
	write(2, error, ft_strlen(error));
	exit(-1);
}
