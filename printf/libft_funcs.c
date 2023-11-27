/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:43:25 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/27 15:43:27 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_strrev - function that reverses the indexs of an array
 * @str: pointer to the string to reverse
 * Return: void.
*/

void	ft_strrev(char *str)
{
	size_t	len;
	size_t	count;
	char	temp;

	len = ft_strlen(str) - 1;
	count = 0;
	while (count < len)
	{
		temp = str[count];
		str[count++] = str[len];
		str[len--] = temp;
	}
}

/**
 * ft_putchar_fd - function the display the output in the corresponding
 * file descriptor.
 * @c: character to output
 * @fd: The file descriptor on which to write
 * Return: void.
*/
int	ft_putchar_fd(char c, int fd)
{
	int	len;

	if (fd < 0)
		return (0);
	len = write (fd, &c, 1);
	return (len);
}

/**
*ft_strlen - function that computes the length of a string
*@s: string
*Return: string's length
*/
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
