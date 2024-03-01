/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:41:34 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/01 16:41:35 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_ptr	rotate_both_stack(stack_ptr a, stack_ptr *b);
stack_ptr	rev_rotate_both_stack(stack_ptr a, stack_ptr *b);

/**
 * rotate_both_stack - executes ra and rb at the same time,
 * its an rr operation
 * @a: pointer to stack a
 * @b: double pointer to stack b
 * Return: pointer to stack a.
*/
stack_ptr	rotate_both_stack(stack_ptr a, stack_ptr *b)
{
	a = rotate(a, NULL);
	*b = rotate((*b), NULL);
	ft_putendl_fd("rr", 1);
	return (a);
}

/**
 * rev_rotate_both_stack - executes rra and rrb operations at
 * the same time, its an rrr operation
 * @a: pointer to stack a
 * @b: double pointer to stack b
 * Return: pointer to stack a.
*/
stack_ptr	rev_rotate_both_stack(stack_ptr a, stack_ptr *b)
{
	a = rev_rotate(a, NULL);
	*b = rev_rotate((*b), NULL);
	ft_putendl_fd("rrr", 1);
	return (a);
}
