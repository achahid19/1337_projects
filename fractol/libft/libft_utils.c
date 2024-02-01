/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:35:27 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/31 17:35:29 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_putchar_fd(char c, int fd);
static void	ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);

/**
 * ft_strncmp - compares n bytes between s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compares
 * Return: 0 if s1 == s2, > 0 if s1 > s2, othwise < 0 if s1 < s2
*/
int	ft_strncmp(const char *s1, const char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		--n;
	}
	return (*s1 - *s2);
}

/**
 * ft_strlen - counts the length of str
 * @str: string
 * Return: length of str
*/
size_t	ft_strlen(const char *str)
{
	if (NULL == str || '\0' == *str)
		return (0);
	return (ft_strlen(str + 1) + 1);
}

/**
 * ft_putendl_fd - function that outputs the string s to the given
 * file descriptor
 * @s: pointer to the string
 * @fd: index of the file descriptor
 * Return: void.
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

/**
 * ft_putchar_fd - function the display the output in the corresponding
 * file descriptor.
 * @c: character to output
 * @fd: The file descriptor on which to write
 * Return: void.
*/
static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}

/**
 * ft_putstr_fd - function that outputs the string s to the given
 * file descriptor
 * @s: pointer to the string
 * @fd: index of the file descriptor
 * Return: void.
*/
static void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	if (!s || fd < 0)
		return ;
	count = 0;
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
}
