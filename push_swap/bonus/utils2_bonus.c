/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:12:01 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 15:12:02 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t		get_stack_size(t_stack_ptr stack);
t_stack_ptr	find_last_node(t_stack_ptr a);
t_stack_ptr	find_blast_node(t_stack_ptr a);
bool		is_sorted(t_stack_ptr a);
void		free_all(char **args, t_stack_ptr a, char **actions);

/**
 * get_stack_size - counts number of nodes on the stack
 * @stack: pointer to the stack
 * Return: stack's size
*/
size_t	get_stack_size(t_stack_ptr stack)
{
	size_t	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/**
 * find_last_node - search for the last node on the stack
 * @a: pointer to the stack
 * Return: pointer to the last node on the stack
*/
t_stack_ptr	find_last_node(t_stack_ptr a)
{
	while (a->next != NULL)
		a = a->next;
	return (a);
}

/**
 * find_blast_node - search on the stack for the node positioned
 * before the last node.
 * @a: pointer to the main stack (a)
 * Return: pointer to a node.
 */
t_stack_ptr	find_blast_node(t_stack_ptr a)
{
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}

/**
 * is_sorted - checks if the values on the stack are sorted
 * @a: pointer to the stack to check
 * Return: fasle if it's not sorted, otherwise true
*/
bool	is_sorted(t_stack_ptr a)
{
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return (false);
		a = a->next;
	}
	return (true);
}

/**
 * 
*/
void	free_all(char **args, t_stack_ptr a, char **actions)
{
	free_args(args);
	free_main_stack(a);
	free_args(actions);
}
