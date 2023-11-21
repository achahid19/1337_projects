/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:48:18 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 14:48:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../printf.h"

/**
 * ft_putnbr_fd - function that outuput n in the given fd
 * @n: integer to output
 * @fd: index of the file descriptor
 * Return: void.
*/
int	ft_putnbr(va_list av)
{
	long int	l;
	size_t		count;

	count = 0;
	l = (long int)va_arg(av, int);
	if (l < 0)
	{
		write (1, "-", 1);
		l *= -1;
		count++;
	}
	if (l >= 0)
	{
		if (l < 10)
		{
			l += 48;
			write (1, &l, 1);
			count++;
		}
		else if (l >= 10)
		{
			ft_putnbr((int)(l / 10));
			ft_putnbr((int)(l % 10));
		}
	}
	return (count);
}
