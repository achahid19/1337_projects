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

stack_ptr	find_last_node(stack_ptr a);
bool		is_sorted(stack_ptr a);
size_t		find_hindex(stack_ptr a);
stack_ptr	find_blast_node(stack_ptr a);
void		get_pos(stack_ptr stack);

/**
 * find_last_node - search for the last node on the stack
 * @a: pointer to the stack
 * Return: pointer to the last node on the stack
*/
stack_ptr	find_last_node(stack_ptr a)
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
bool	is_sorted(stack_ptr a)
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
size_t	find_hindex(stack_ptr a)
{
	size_t	index;

	index = a->index;
	while (a != NULL)
	{
		if (a->index > index)
			index = a->index;
		a = a->next;
	}
	return (index);
}

/**
 * find_blast_node - search on the stack for the node positioned
 * before the last node.
 * @a: pointer to the main stack (a)
 * Return: pointer to a node.
 */
stack_ptr	find_blast_node(stack_ptr a)
{
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}

/**
 * get_pos - assign a position for each node starting from 0 to  n (size_size - 1)
 * @stack: pointer to the stack
 * Return: void.
*/
void	get_pos(stack_ptr stack)
{
	stack_ptr	tmp;
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
