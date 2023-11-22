/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:32:12 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 10:32:17 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_printf - function that processes the format string and format
 * the ouptut depending on the format specifier
 * @format: the format string
 * Return: length of formated output, otherwise -1 if fails
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	len = 0;
	ft_conversion(format, &len, args);
	va_end(args);
	return (len);
}
