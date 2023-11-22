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
