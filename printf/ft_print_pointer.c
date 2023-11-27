/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:27:32 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/24 08:27:34 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_printlow_hex - function that converts a base 10 to base 16
 * @n: number to convert
 * Return: length of formated output
*/
int	ft_printlow_hex(long int n);

/**
 * ft_print_prointer - function that prints an address in hexadecimal format
 * @args: list of arguments
 * Return: length of the formated output
*/
int	ft_print_pointer(va_list args)
{
	void				*ptr;
	char				*str;
	int					len;
	long int			a;

	str = "(nil)";
	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		len = write (1, str, ft_strlen(str));
		return (len);
	}
	a = (long int)ptr;
	write (1, "0x", 2);
	len = ft_printlow_hex(a);
	return (len + 2);
}

int	ft_printlow_hex(long int n)
{
	long int	l;
	size_t		count;
	char		buffer[13];
	int			remainder;

	l = n;
	count = 0;
	if (l == 0)
		buffer[count++] = '0';
	while (l > 0)
	{
		remainder = l % 16;
		if (remainder < 10)
			buffer[count++] = remainder + '0';
		else
			buffer[count++] = remainder - 10 + 'a';
		l /= 16;
	}
	buffer[count] = '\0';
	ft_strrev(buffer);
	write (1, buffer, count);
	return ((int)count);
}
