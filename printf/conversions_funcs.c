/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:32:32 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 10:32:34 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putchar - function that prints a char on stdout
 * @args: the list that contains the character to prints
 * Returns: 1 for one char
*/
int	ft_putchar(va_list args)
{
	char	c;

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
	char	*str;

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
	char		buffer[12];

	l = va_arg(args, int);
	chars_n = 0;
	if (l < 0)
		ft_negative(&l, buffer, &chars_n);
	else if (l == 0)
		ft_zero(buffer, &chars_n);
	ft_length(l, &chars_n);
	count = chars_n - 1;
	temp = 0;
	while (l > 0)
	{
		buffer[count] = l % 10 + 48;
		l /= 10;
		count--;
	}
	buffer[chars_n] = '\0';
	write (1, buffer, chars_n);
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
