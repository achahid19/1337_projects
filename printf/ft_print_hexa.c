/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:04:38 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/23 11:04:40 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_printlow_hexa - function that converts a base 10 to base 16
 * @args: list of the arguments
 * Return: length of formated output
*/
int	ft_printlow_hexa(va_list args)
{
	int long	l;
	size_t		count;
	char		buffer[9];
	int			remainder;

	l = (unsigned int)va_arg(args, int);
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

/**
 * ft_printup_hexa - function that converts a base 10 to base 16
 * @args: list of the arguments
 * Return: length of formated output
*/
int	ft_printup_hexa(va_list args)
{
	long int	l;
	size_t		count;
	char		buffer[9];
	int			remainder;

	l = (unsigned int)va_arg(args, int);
	count = 0;
	if (l == 0)
		buffer[count++] = '0';
	while (l > 0)
	{
		remainder = l % 16;
		if (remainder < 10)
			buffer[count++] = remainder + '0';
		else
			buffer[count++] = remainder - 10 + 'A';
		l /= 16;
	}
	buffer[count] = '\0';
	ft_strrev(buffer);
	write (1, buffer, count);
	return ((int)count);
}
