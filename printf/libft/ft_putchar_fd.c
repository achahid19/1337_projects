/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:40:59 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 10:41:01 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../printf.h"

/**
 * ft_putchar_fd - function the display the output in the corresponding
 * file descriptor.
 * @c: character to output
 * @fd: The file descriptor on which to write
 * Return: void.
*/
int	ft_putchar(va_list av)
{
	char	c;

	c = va_arg(av, int);
	write (1, &c, 1);
	return (1);
}
