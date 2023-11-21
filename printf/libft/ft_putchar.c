#include "../ft_printf.h"

/**
 * ft_putchar - function that prints a char on stdout
 * @c: character to prints
 * Return: void
*/
int	ft_putc(int c)
{
	write (1, &c, 1);
	return (1);
}
