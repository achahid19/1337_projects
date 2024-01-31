/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:44:55 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/30 15:44:56 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void ft_julia_args_handler(const char *arg1, const char *arg2);

/**
 * ft_check_julia_input - checks the argument passed to the program
 * when the Julia Set is called
 * @arg1: pointer to the first argument
 * @arg2: pointer to the second argument
 * Return: void.
*/
void	ft_check_julia_input(const char *arg1, const char *arg2)
{
	size_t	i;

	i = 0;
	while (++i <= ft_strlen(arg1) - 1)
	{
		if('+' == arg1[i] || '-' == arg1[i])
			exit(EXIT_FAILURE); // Handle TODO errors.
	}
	i = 0;
	while (++i <= ft_strlen(arg2) - 1)
	{
		if ('+' == arg2[i] || '-' == arg2[i])
			exit(EXIT_FAILURE); // TODO errors hanler
	}
	ft_julia_args_handler(arg1, arg2);
	return ;
}

/**
 * ft_julia_args_hanlder - handle the parsing of the arguments passed
 * to the program
 * @arg1: pointer to the first argument
 * @arg2: pointer to the second argument
 * Return: void.
*/
static void ft_julia_args_handler(const char *arg1, const char *arg2)
{
	while (*arg1)
	{
		if (!(*arg1 >= '0' && *arg1 <= '9') && (*arg1 != '+' && *arg1 != '-')
			&& *arg1 != '.' && *arg1 != ' ')
			exit (5); // TODO errors handling.
		arg1++;
	}
	while (*arg2)
	{
		if (!(*arg2 >= '0' && *arg2 <= '9') && (*arg2 != '+' && *arg2 != '-')
			&& *arg2 != '.' && *arg2 != ' ')
			exit (5); // TODO errors hander
		arg2++;
	}
	return ;
}
