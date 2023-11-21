#include "ft_printf.h"

/**
 * ft_get_func - function that matches the format specifier given with
 * the corresponding function to process
 * @c: format specifier to check
 * @list: list of arguments given to printf functions
 * Return: The length of the return value of the corresponding function
*/
int	(*ft_get_func(char c))(va_list args)
{
	get_func_t	list[] = {
		{'c', ft_putchar},
		{'d', ft_putnbr},
		{'i', ft_putnbr},
		{'s', ft_putstr},
		{'%', ft_percent}
	};
	size_t	count;

	count = 0;
	while (count < 5)
	{
		if (list[count].c == c)
			return (list[count].f);
		count++;
	}
	return (NULL);
}
