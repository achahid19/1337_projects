/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:04:38 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 11:04:39 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	exit_error(char *error, int fd);
void	ft_print_error(char *to_free);
void	free_args(char **args);
void	free_and_exit(t_stack_ptr stack, char **args, int status);
void	free_stack(t_stack_ptr stack);

/**
 * exit_error - writes an msg error on stderr or stdout
 * and exit the process with -1 status.
 * @error: pointer to the error message.
 * @fd: file descriptor (integer), where to display the msg.
 * Return: void.
*/
void	exit_error(char *error, int fd)
{
	if (2 == fd)
		write(2, error, ft_strlen(error));
	else if (1 == fd)
		write(1, error, ft_strlen(error));
	exit(-1);
}

/**
 * ft_print_error2 - prints a msg error on stderr
 * and exit() the process with -1 status
 * @args: pointer to the memory occupied by the arguments
 * and its meant to be freed before exiting the process
 * Return: void.
*/
void	ft_print_error(char *to_free)
{
	if (to_free != NULL)
		free(to_free);
	exit_error("Error\n", 2);
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

/**
 * free_args - freed all memory allocated to arguments
 * @args: pointer to arguments
 * Return: void.
*/
void	free_args(char **args)
{
	size_t	index;

	if (NULL == args)
		return ;
	index = 0;
	while (args[index] != NULL)
	{
		free(args[index]);
		index++;
	}
	free(args);
	return ;
}

/**
 * free_and_exit - In case an error occur while allocation
 * memory for new nodes to build the stack, this function
 * frees all the stack a and the memory allocated to gather
 * all the arguments for checking purposes, finally it exit
 * the process with a status of -1.
 * @stack: pointer to the stack to free
 * @args: double pointer to arguments
 * Return: void.
*/
void	free_and_exit(t_stack_ptr stack, char **args, int status)
{
	if (stack != NULL)
		free_stack(stack);
	if (args != NULL)
		free_args(args);
	exit(status);
}
