/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:32:44 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 10:32:46 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_check_specifier - function that checks if the specifier given
 * is adequate or not
 * @c: specifier to check
 * Return: 1 if true, 0 if false
*/
int	ft_check_specifier(char c)
{
	return (c == 'c' || c == '%' || c == 's' || c == 'i' || c == 'd'
		|| c == 'x' || c == 'X');
}

/**
 * ft_process_fs - function that processes the format string, matches the format
 * specifier with the corresponding function, and output the formated output
 * @format: pointer to the string format
 * @len: pointer to the lenght of the formated output
 * @args: list of all arguments
 * Return: void.
*/
void	ft_conversion(const char *format, size_t *len, va_list args)
{
	size_t	l;
	size_t	count;
	int		(*f)(va_list);

	count = 0;
	l = *len;
	while (format[count])
	{
		if (format[count] != '%')
			write (1, &format[count], 1);
		else if (format[count] == '%')
		{
			if (!ft_check_specifier(format[count + 1]))
			{
				write (1, &format[count++], 1);
				continue ;
			}
			f = ft_get_func(format[++count]);
			l += (*f)(args) - 2;
		}
		count++;
	}
	*len = l + count;
}

/**
 * ft_negative - function that handles the case if a negative
 * integer is passed to ft_putnbr function
 * @l: integer passed as argument
 * @buffer: the temporary memory area where to store the digits
 * of l to output it when the buffer is filled
 * @n: number of chars to output
 * Return: void
*/
void	ft_negative(size_t *l, char *buffer, size_t *n)
{
	buffer[0] = '-';
	*n = *n + 1;
	*l = *l * -1;
}

/**
 * ft_zero - handles the case of zero is passed to
 * ft_putnbr function
 * @buffer: temporary memory area
 * @n: counts the number of chars to output
 * Return: void.
*/
void	ft_zero(char *buffer, size_t *n)
{
	buffer[0] = '0';
	*n = *n + 1;
}

/**
 * ft_length - function that counts the length
 * of the integer l
 * @l: integer
 * @n: counts number of chars to output
 * Return: void.
*/
void	ft_length(size_t l, size_t *n)
{
	while (l > 0)
	{
		*n = *n + 1;
		l /= 10;
	}
}
