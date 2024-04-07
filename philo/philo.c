#include "philo.h"

/**
 * main - Entry point
 * Description: ...
 * 
 * Return: Always 0 (Success).
*/
int	main(int ac, char *av[])
{
	if (ac < 5 || ac > 6 || check_inputs(av) == false)
		print_error("Invalid input!\n");

	return (0);
}
