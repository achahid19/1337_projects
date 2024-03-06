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

#include "../includes/push_swap.h"

void		target_pos(t_stack_ptr a, t_stack_ptr *b);
static int	find_target(t_stack_ptr a, size_t index_b,
				int target_idx, int target_pos);
t_stack_ptr	saveof3(t_stack_ptr a, t_stack_ptr *b, size_t size_a);
void		cost_get(t_stack_ptr a, t_stack_ptr *b);
int			ft_abs(int num);

/**
 * target_pos - finds the target position for each B element into stack a,
 * it will be used to calculate the cost of moving each element
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b
 * @size_a: size of main stack (a)
 * Return: void.
*/
void	target_pos(t_stack_ptr a, t_stack_ptr *b)
{
	t_stack_ptr	tmp_b;
	int			target_pos;

	tmp_b = (*b);
	get_pos(a);
	get_pos((*b));
	target_pos = 0;
	while (tmp_b != NULL)
	{
		target_pos = find_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

/**
 * find_target - finds the optimal target position in stack A
 * for each element in stack b.
 * Compares stack a's indexes with satck b's indexes,
 * if index a > index b then we target the element
 * to place B element into A position.
 * If any A index greater than B index is not found,
 * then we target the smallest A element as target position
 * of B element.
 * @a: pointer to main stack (a)
 * @index_b: index for B element
 * @target_idx: index of the A element to target
 * @target_pos: position of the A element to target
 * Return: the positon to target in stack a.
*/
static int	find_target(t_stack_ptr a, size_t index_b,
				int target_idx, int target_pos)
{
	t_stack_ptr	tmp_a;

	tmp_a = a;
	while (tmp_a != NULL)
	{
		if (tmp_a->index > index_b && (int)tmp_a->index < target_idx)
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
		if ((int)tmp_a->index < target_idx)
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
 * for effeciency, the values with lowest indexes are pushed first
 * (they are compared to the mediane "size_a / 2", in case the index is lower
 * than the mediane its pushed to stack b), on stack a the values
 * with higher indexes (higher than the mediane).
 * @a: pointer to main stack
 * @b: double pointer to stack b
 * @size_a: size of main stack (a)
 * Return: pointer to the main stack.
*/
t_stack_ptr	saveof3(t_stack_ptr a, t_stack_ptr *b, size_t size_a)
{
	size_t	index;
	int		b_push;
	int		save_values;

	index = 0;
	b_push = 0;
	save_values = 3;
	while (index < size_a && b_push < (int)size_a / 2)
	{
		if (a->index <= size_a / 2)
		{
			a = push(a, b, "pb");
			b_push += 1;
		}
		else
			a = rotate(a, "ra");
		index++;
	}
	while (size_a - b_push > save_values)
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
 * cost of a represents the cost to get B element
 * on the right position in stack a.
 * In case of getting a negative cost, that means
 * that the element is in the bottom half of the stack,
 * the opposite remains right.
 * @a: pointer to main stack (a)
 * @b: double pointer to stack b
 * Return: void
*/
void	cost_get(t_stack_ptr a, t_stack_ptr *b)
{
	t_stack_ptr	tmp_b;
	size_t		size_a;
	size_t		size_b;
	int			i;

	tmp_b = (*b);
	size_a = get_stack_size(a);
	size_b = get_stack_size((*b));
	i = -1;
	while (tmp_b != NULL)
	{
		tmp_b->cb = tmp_b->pos;
		if (tmp_b->pos > ((int)size_b / 2))
			tmp_b->cb = i * (size_b - tmp_b->pos);
		tmp_b->ca = tmp_b->target_pos;
		if (tmp_b->target_pos > ((int)size_a / 2))
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
