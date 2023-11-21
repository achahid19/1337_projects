/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:11:47 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 14:11:49 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../printf.h"

/**
 * ft_putstr_fd - function that outputs the string s to the given
 * file descriptor
 * @s: pointer to the string
 * @fd: index of the file descriptor
 * Return: void.
*/
int	ft_putstr(va_list av)
{
	size_t	count;
	char	*str;

	str = va_arg(av, char *);
	if (str == NULL)
		str = "null";
	count = 0;
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	return (count);
}
