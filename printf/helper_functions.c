#include "ft_printf.h"

/**
 * ft_check_specifier - function that checks if the specifier given is adequate or not
 * @c: specifier to check
 * Return: 1 if true, 0 if false
*/
int	ft_check_specifier(char c)
{
	return (c == 'c' || c == '%' || c == 's' || c == 'i' || c == 'd' ||
			c == 'x' || c == 'X');
}
