#include "printf.h"

/**
 * ft_check_specifier - function that checks if the format specifier entered
 * correspond to a function
 * @c: character to check
 * Return: an int greater than 0 if true, otherwise 0 if false
*/
int	ft_check_specifier(char c)
{
	return (c == '%' || c == 'c' || c == 'd' || c == 'i') || c == 's';
}
