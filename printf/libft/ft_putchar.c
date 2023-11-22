/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:32:59 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 10:33:01 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * ft_putchar - function that prints a char on stdout
 * @c: character to prints
 * Return: void
*/
int	ft_putc(int c)
{
	write (1, &c, 1);
	return (1);
}
