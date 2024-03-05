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

#include "../includes/push_swap.h"

void	ft_print_error(char *to_free);
void	ft_print_error2(char **args);
void	free_main_stack(t_stack_ptr a);
void	free_args(char **args);

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
void	free_and_exit(t_stack_ptr stack, char **args)
{
	if (stack != NULL)
		free_main_stack(stack);
	free_args(args);
	exit(-1);
}

/**
 * free_main_stack - frees all the nodes building the linked list of the stack
 * @a: pointer to stack
 * Return: void.
*/
void	free_main_stack(t_stack_ptr a)
{
	t_stack_ptr	tmp;

	if (NULL == a)
		return ;
	tmp = a;
	if (NULL == tmp->next)
	{
		free(a);
		return ;
	}
	while (tmp != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
		tmp = a->next;
	}
	free(a);
	return ;
}

/**
 * free_args - freed all memory allocated to arguments
 * @args: pointer to arguments
 * Return: void.
*/
void	free_args(char **args)
{
	size_t	index;

	index = 0;
	while (args[index] != NULL)
	{
		free(args[index]);
		index++;
	}
	free(args);
	return ;
}
