/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:16:45 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/25 15:16:47 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_ptr	find_last_node(t_stack_ptr a);
t_bool		is_sorted(t_stack_ptr a);
size_t		find_hindex(t_stack_ptr a);
t_stack_ptr	find_blast_node(t_stack_ptr a);
void		get_pos(t_stack_ptr stack);

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
 * is_sorted - checks if the values on the stack are sorted
 * @a: pointer to the stack to check
 * Return: fasle if it's not sorted, otherwise true
*/
t_bool	is_sorted(t_stack_ptr a)
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
 * find_hindex - search for the highest index on the stack
 * @a: pointer to the main stack (a)
 * Return: highest index found.
*/
size_t	find_hindex(t_stack_ptr a)
{
	size_t	highest_index;

	highest_index = a->index;
	while (a != NULL)
	{
		if (a->index > highest_index)
			highest_index = a->index;
		a = a->next;
	}
	return (highest_index);
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
 * get_pos - assign a position for each node starting
 * from 0 to  n (size_size - 1)
 * @stack: pointer to the stack
 * Return: void.
*/
void	get_pos(t_stack_ptr stack)
{
	t_stack_ptr	tmp;
	int			counter;

	tmp = stack;
	counter = 0;
	while (tmp != NULL)
	{
		tmp->pos = counter;
		tmp = tmp->next;
		counter++;
	}
}
