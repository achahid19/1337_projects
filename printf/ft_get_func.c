/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:31:54 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 10:31:57 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_get_func	list[8];
	size_t		count;

	count = 0;
	list[0].c = 'c';
	list[0].f = ft_putchar;
	list[1].c = 'd';
	list[1].f = ft_putnbr;
	list[2].c = 'i';
	list[2].f = ft_putnbr;
	list[3].c = '%';
	list[3].f = ft_percent;
	list[4].c = 's';
	list[4].f = ft_putstr;
	list[5].c = 'u';
	list[5].f = ft_unsigned_nbr;
	list[6].c = 'x';
	list[6].f = ft_printlow_hexa;
	list[7].c = 'X';
	list[7].f = ft_printup_hexa;
	while (count < 8)
	{
		if (list[count].c == c)
			return (list[count].f);
		count++;
	}
	return (NULL);
}
