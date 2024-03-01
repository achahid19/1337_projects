/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:49:24 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/29 09:49:26 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		target_pos(stack_ptr a, stack_ptr *b);
static int	find_target(stack_ptr a, size_t index_b, int target_idx, int target_pos);
stack_ptr	saveOf3(stack_ptr a, stack_ptr *b, size_t size_a);
void		cost_get(stack_ptr a, stack_ptr *b);
int			ft_abs(int num);

/**
 * target_pos - finds the target position for each B element into stack a,
 * it will be used to calculate the cost of moving each element
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b
 * @size_a: size of main stack (a)
 * Return: void.
*/
void	target_pos(stack_ptr a, stack_ptr *b)
{
	stack_ptr	tmp_b;
	int			target_pos;

	tmp_b = (*b);
	get_pos(a);
	get_pos((*b));
	target_pos = 0;
	// Loop until stack b is pointing to NULL
	while (tmp_b != NULL)
	{
		target_pos = find_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

/**
 * find_target - finds the optimal target position in stack A for each element in stack b
 * Compares stack a's indexes with satck b's indexes, if index a > index b
 * then we target the element to place B element into A position
 * If any A index greater than B index is not found, then we target the smallest A element
 * as target position of B element
 * @a: pointer to main stack (a)
 * @index_b: index for B element
 * @target_idx: index of the A element to target
 * @target_pos: position of the A element to target
 * Return: the positon to target in stack a.
*/
static int	find_target(stack_ptr a, size_t index_b, int target_idx, int target_pos)
{
	stack_ptr	tmp_a;

	tmp_a = a;
	while (tmp_a != NULL)
	{
		// compare node's index of stack a, if index_a > index_b then it's the targeted node
			// note that, to not ruin the sort of stack a we check if index_a is < target_index
		if (tmp_a->index > index_b && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = a;
	while (tmp_a != NULL)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/**
 * saveOf3 - push all elements of stack a to stack b except the last 3 elements.
 * for effeciency, the values with lowest indexes are pushed first, trying to keep
 * on stack a the values with higher indexes.
 * @a: pointer to main stack
 * @b: double pointer to stack b
 * @size_a: size of main stack (a)
 * Return: pointer to the main stack.
*/
stack_ptr	saveOf3(stack_ptr a, stack_ptr *b, size_t size_a)
{
	size_t	index;
	int		b_push;

	index = 0;
	b_push = 0;
	while (size_a > 6 && index < size_a && b_push < (int)size_a / 2)
	{
		// push the lowest indexes
		if (a->index <= size_a / 2)
		{
			a = push(a, b, "pb");
			b_push += 1;
		}
		else /* if the index if above the mediane */
			a = rotate(a, "ra");
		index++;
	}
	// push the remaining values to keep only 3 nums on stack a.
	while (size_a - b_push > 3)
	{
		a = push(a, b, "pb");
		b_push += 1;
	}
	return (a);
}

/**
 * cost_get - Calculate the cost of moving each B element into the correct
 * postion in stack a;
 * cost of b represents the cost to get a B element on the top of stack b
 * cost of a represents the cost to get B element on the right position in stack a.
 * In case of getting a negative cost, that means that the element is in the bottom
 * half of the stack, the opposite remains right.
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b
 * Return: void
*/
void	cost_get(stack_ptr a, stack_ptr *b)
{
	stack_ptr 	tmp_a;
	stack_ptr 	tmp_b;
	size_t		size_a;
	size_t		size_b;
	int			i;

	tmp_a = a;
	tmp_b = (*b);
	size_a = get_stack_size(a);
	size_b = get_stack_size((*b));
	i = -1;
	while (tmp_b != NULL)
	{
		tmp_b->cb = tmp_b->pos;
		// the elements that are > stack b size will get a negative cost
			// the negative costs means that they are situed on the bottom half of the stack
			// so in that case a 'rrb' operation is effecient to execute than 'rb'
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cb = i * (size_b - tmp_b->pos);
		tmp_b->ca = tmp_b->target_pos;
		// Same logic here, if the target position is greater that stack's size of a,
		// a negative value is assigned to the cost
		if (tmp_b->target_pos > (size_a / 2))
			tmp_b->ca = i * (size_a - tmp_b->target_pos);
		tmp_b = tmp_b->next;
	}
}

/**
 * ft_abs - convert a negative number to a positive one
 * @num: integer
 * Return: Absolute value of num
*/
int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
