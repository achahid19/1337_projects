/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:18:34 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/13 16:18:37 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * ft_error_print - print an error message to stderr
 * @msg: message to print
 * Return: exit program execution with status of 1.
*/
int	ft_error_print(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

/**
 * ft_exit_failure - exit the program execution with error
 * Return: exit status
*/
int	ft_error_exit(void)
{
	perror("\033[31mError pipex");
	exit(1);
}

/**
 * free_and_exit - function that frees the memory pointed by to_free
 * and print a msg error to stderr
 * @msg: message to output on stderr
 * @to_free: pointer to the memory to be freed
 * Return: void.
*/
void	free_and_exit(char *msg, char *to_free)
{
	free(to_free);
	ft_error_print(msg);
}
