/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:02:38 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 15:02:39 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_stack_ptr	rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);
t_stack_ptr	rev_rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);
void		swap_both(t_stack_ptr a, t_stack_ptr *b);

/**
 * rotate_both_stack - executes ra and rb at the same time,
 * its an rr operation
 * @a: pointer to stack a
 * @b: double pointer to stack b
 * Return: pointer to stack a.
*/
t_stack_ptr	rotate_both_stack(t_stack_ptr a, t_stack_ptr *b)
{
	a = rotate(a);
	*b = rotate((*b));
	return (a);
}

/**
 * rev_rotate_both_stack - executes rra and rrb operations at
 * the same time, its an rrr operation
 * @a: pointer to stack a
 * @b: double pointer to stack b
 * Return: pointer to stack a.
*/
t_stack_ptr	rev_rotate_both_stack(t_stack_ptr a, t_stack_ptr *b)
{
	a = rev_rotate(a);
	*b = rev_rotate((*b));
	return (a);
}

/**
 * swap_both - execute swap operation on stack a and b
 * at the same time.
 * @a: pointer to main stack (a)
 * @b: double pointer to temporary stack (b)
 * Return: void.
*/
void	swap_both(t_stack_ptr a, t_stack_ptr *b)
{
	swap(a);
	swap((*b));
}
