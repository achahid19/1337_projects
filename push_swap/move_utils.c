/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:08 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/01 15:09:09 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_ptr			lowest_cost_move(stack_ptr a, stack_ptr *b);
static stack_ptr	stack_move(stack_ptr a, stack_ptr *b, int ca, int cb);
static stack_ptr	rotate_stack_a(stack_ptr a, int ca);
static void			rotate_stack_b(stack_ptr *b, int cb);

/**
 * lowest_cost_move - Seach for a B element with the lowest cost to move it
 * on stack into the correct position
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b (temporaty stack)
 * Return: pointer to main stack (a)
*/
stack_ptr	lowest_cost_move(stack_ptr a, stack_ptr *b)
{
	stack_ptr	tmp_b;
	int			ca;
	int			cb;
	int			lowest;

	lowest = INT_MAX;
	tmp_b = (*b);
	while (tmp_b != NULL)
	{
		if (ft_abs(tmp_b->ca) + ft_abs(tmp_b->cb) < ft_abs(lowest))
		{
			lowest = ft_abs(tmp_b->ca) + ft_abs(tmp_b->cb);
			cb = tmp_b->cb;
			ca = tmp_b->ca;
		}
		tmp_b = tmp_b->next;
	}
	a = stack_move(a, b, ca, cb);
	return (a);
}

/**
 * stack_move - execute the move to get the B element
 * on the right position in stack a.
 * If the costs of a and b both have same sign (pos or neg)
 * they will be rotated or rev_rotated simultaneously. Otherwise,
 * each element will be rotated or rev_rotated individually before
 * pushing the element on the top of stack b to stack a.
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b (temporaty stack)
 * @ca: cost of moving B element to stack a
 * @cb: cost of moving a B element to the top of stack b
 * Return: pointer to the main stack (a)
*/
static stack_ptr	stack_move(stack_ptr a, stack_ptr *b, int ca, int cb)
{
	// rotate both stacks simultaneously
	while (ca > 0 && cb > 0)
	{
		a = rotate(a, "ra"); // TODO rr
		*b = rotate((*b), "rb");
		ca--;
		cb--;
	}
	// rev_rotate both stack simultaneously
	while (ca < 0 && cb < 0)
	{
		a = rev_rotate(a, "rra"); // TODO rrr
		*b = rev_rotate((*b), "rrb");
		ca++;
		cb++;
	}
	// individual rotation
	a = rotate_stack_a(a, ca);
	rotate_stack_b(b, cb);
	a = push(a, b, "pa");
	// if is not sorted yet, rotate or rev_rotate until the lowest index
	// is at the top of the main stack.
	return (a);
}

/**
 * rotate_stack_a - make rotation operations until we hit
 * the right position of stack a, all depeding on the cost;
 * if cost of a is positive then we execute rotate operations
 * (cost times), otherwise rev_rotate is executed if the sign
 * the cost is negative
 * @a: pointer to main stack (a).
 * @cost: integer representing the cost to move B element to
 * the right position in stack a
 * Return: pointer to main stack (a).
*/
static stack_ptr	rotate_stack_a(stack_ptr a, int ca)
{
	while (ca != 0)
	{
		if (ca < 0)
		{
			a = rev_rotate(a, "rra");
			++ca;
		}
		else if (ca > 0)
		{
			a = rotate(a, "ra");
			--ca;
		}
	}
	return (a);
}

/**
 * rotate_stack_b - make rotation operations until we hit
 * the right position of stack b, all depending on the cost of b;
 * if cost of b is + then we execute rotate operations (cost times),
 * otherwise rev_rotate is executed if the sign is -.
 * @b: double pointer to the temporary stack (b).
 * @cb: the cose to get a B element to the top of stack b
 * Return: void.
*/
static void	rotate_stack_b(stack_ptr *b, int cb)
{
	while (cb != 0)
	{
		if (cb < 0)
		{
			*b = rev_rotate((*b), "rrb");
			++cb;
		}
		else if (cb > 0)
		{
			*b = rotate((*b), "rb");
			--cb;
		}
	}
}
