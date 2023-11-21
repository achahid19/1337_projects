#include "printf.h"

/**
 * get_function - function that matches the format specifier with
 * its corresponding function
 * 
*/
int	(*ft_get_specifier(char c))(va_list av)
{
	conversion_t	list[] = {
		{'c', ft_putchar},
		{'i', ft_putnbr},
		{'d', ft_putnbr},
		{'s', ft_putstr},
		{'%', ft_putchar}
	};
	size_t	count;

	count = 0;
	while (list[count].c != c)
	{
		count++;
		if (list[count].c == c)
			return (list[count].f);
	}
	return (NULL);
}
