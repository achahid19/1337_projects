/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shifting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:19:18 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/01 15:19:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_ptr	stack_shifting(stack_ptr a);
static int	lindex_pos(stack_ptr stack);

/**
 * stack_shifting - shift the stack until we got the element with
 * lowest index at the top of stack a.
 * @a: poiter to the main stack (a)
 * Return: pointer to stack a (main stack)
*/
stack_ptr	stack_shifting(stack_ptr a)
{
	size_t	size_a;
	int		lidx_pos;

	size_a = get_stack_size(a);
	lidx_pos = lindex_pos(a);
	if (lidx_pos <= (size_a / 2))
	{
		while (lidx_pos > 0)
		{
			a = rotate(a, "ra");
			lidx_pos--;
		}
	}
	else
	{
		while (lidx_pos < size_a)
		{
			a = rev_rotate(a, "rra");
			lidx_pos++;
		}
	}
	return (a);
}

/**
 * lindex_pos - Gets the position of the lowest index on the stack
 * @stack: pointer to a stack
 * Return: Position of the lowest index on stack
*/
static int	lindex_pos(stack_ptr stack)
{
	int	lindex;
	int	lowest_pos;

	get_pos(stack);
	lindex = INT_MAX;
	lowest_pos = stack->pos;
	while (stack != NULL)
	{
		if (stack->index < lindex)
		{
			lindex = stack->index;
			lowest_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (lowest_pos);
}
