/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_erros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:28:50 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/23 16:28:53 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ft_print_error - prints a message error on stderr
 * and exit() the current process with -1 as a status
 * @free: pointer to the memory allocated to be freed before exiting the process
 * Return: void.
*/
void	ft_print_error(char *to_free)
{
	if (to_free != NULL)
		free(to_free);
	ft_putendl_fd("Error", 2);
	exit(-1);
}

/**
 * ft_print_error2 - prints a msg error on stderr
 * and exit() the process with -1 status
 * @args: pointer to the memory occupied by the arguments
 * and its meant to be freed before exiting the process
 * Return: void.
*/
void	ft_print_error2(char **args)
{
	if (*args != NULL)
		free_args(args);
	ft_print_error(NULL);
}
