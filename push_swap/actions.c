/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:47:36 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/25 10:47:38 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(stack_ptr a, char *str);
stack_ptr	ra(stack_ptr a);
stack_ptr	rra(stack_ptr a);

/**
 * swap - executes a swap between the 2 values on the top of the stack
 * @a: pointer to the stack
 * @str: pointer to the operation to execute
 * Return: void.
 * 
*/
void	swap(stack_ptr a, char *str)
{
	int	tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
	tmp = a->index;
	a->index = a->next->index;
	a->next->index = tmp;
	if (str != NULL)
		ft_putendl_fd(str, 1);
}

/**
 * ra - swipe up stack's order,
 * e.g: the first node becomes the last one, the second one
 * becomes the first one and the third one becomes the second one
 * (2, 4, 6) => (4, 6, 2)
 * @a: pointer to the main stack
 * Return: pointer to the main stack with the new order.
*/
stack_ptr	ra(stack_ptr a)
{
	stack_ptr   last_node;
	stack_ptr   tmp;

	// make the last node points to the first node
	last_node = find_last_node(a);
	last_node->next = a;
	// stack pointer should point to the second node
	tmp = a;
	a = a->next;
	// update the node.next to NULL (last node on the stack)
	tmp->next = NULL;
	ft_putendl_fd("ra", 1);
	return (a);
}

/**
 * rra - swipe down stack's order,
 * e.g: (2, 4, 6) => (6, 2, 4)
 * @a: pointer to the main stack
 * Return: pointer to the main stack with the new order.
*/
stack_ptr	rra(stack_ptr a)
{
	stack_ptr	tmp;
	stack_ptr	last;
	stack_ptr	before_last;

	// find the before last node
	before_last = find_blast_node(a);
	// make a temporary pointer to the first node
	tmp = a;
	// make the last node points to the first node
	last = find_last_node(a);
	last->next = tmp;
	// make the last node points to NULL
	before_last->next = NULL;
	// make the stack pointer points to the node that becomes the first
	a = last;
	ft_putendl_fd("rra", 1);
	return (a);
}
