#include "ft_printf.h"

/**
 * ft_putchar - function that prints a char on stdout
 * @args: the list that contains the character to prints
 * Returns: 1 for one char
*/
int	ft_putchar(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	write (1, &c, 1);
	return (1);
}

/**
 * ft_putstr - function that prints a string on stdout
 * @args: the list that contains string to prints
 * Return: length of the string
*/
int	ft_putstr(va_list args)
{
	unsigned char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}

/**
 * ft_putnbr - funtion that takes a integer as argument and prints it on stdout
 * @n: the list that contains the integer to prints
 * Return: number of digits printed on stdout
*/
int	ft_putnbr(va_list args)
{
	long int	l;
	size_t		chars_n;
	size_t		count;
	long int	temp;
	
	l = va_arg(args, long int);
	chars_n = 0;
	if (l < 0)
	{
		l = -l;
		write (1, "-", 1);
		chars_n++;
	}
	else if (l == 0)
		chars_n++;
	temp = l;
	while (temp--)
		chars_n++;
	count = 0;
	temp = 0;
	while (count < chars_n)
	{
		temp = l % 10 + 48;
		write (1, &temp, 1);
		l /= 10;
		count++;
	}
	return ((int)chars_n);
}

/**
 * ft_percent - function that prints '%' for the format specifier %%
 * @args: list of arguments
 * Return: 1 of the '%' printed.
*/
int	ft_percent(va_list args)
{
	(void)args;
	return (ft_putc('%'));
}
