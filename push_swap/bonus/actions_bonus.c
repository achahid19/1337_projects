/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:02:49 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 15:02:51 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void		swap(t_stack_ptr a, char *str);
t_stack_ptr	rotate(t_stack_ptr stack, char *str);
t_stack_ptr	rev_rotate(t_stack_ptr stack, char *str);
t_stack_ptr	push(t_stack_ptr a, t_stack_ptr *b, char *str);

/**
 * swap - executes a swap between the 2 values on the top of the stack
 * @a: pointer to the stack
 * @str: pointer to the operation to execute
 * Return: void.
*/
void	swap(t_stack_ptr a, char *str)
{
	int	tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
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
t_stack_ptr	rotate(t_stack_ptr stack, char *str)
{
	t_stack_ptr	last_node;
	t_stack_ptr	tmp;

	if (get_stack_size(stack) < 2)
		return (stack);
	last_node = find_last_node(stack);
	last_node->next = stack;
	tmp = stack;
	stack = stack->next;
	tmp->next = NULL;
	if (str != NULL)
		ft_putendl_fd(str, 1);
	return (stack);
}

/**
 * rra - swipe down stack's order,
 * e.g: (2, 4, 6) => (6, 2, 4)
 * @a: pointer to the main stack
 * Return: pointer to the main stack with the new order.
*/
t_stack_ptr	rev_rotate(t_stack_ptr stack, char *str)
{
	t_stack_ptr	tmp;
	t_stack_ptr	last;
	t_stack_ptr	before_last;

	if (get_stack_size(stack) < 2)
		return (stack);
	before_last = find_blast_node(stack);
	tmp = stack;
	last = find_last_node(stack);
	last->next = tmp;
	before_last->next = NULL;
	stack = last;
	if (str)
		ft_putendl_fd(str, 1);
	return (stack);
}

/**
 * push -
*/
t_stack_ptr	push(t_stack_ptr a, t_stack_ptr *b, char *str)
{
	t_stack_ptr	tmp;

	if (0 == ft_strncmp(str, "pb", ft_strlen(str)))
	{
		tmp = a->next;
		a->next = (*b);
		(*b) = a;
		a = tmp;
	}
	else if (0 == ft_strncmp(str, "pa", ft_strlen(str)))
	{
		tmp = (*b)->next;
		(*b)->next = a;
		a = (*b);
		(*b) = tmp;
	}
	if (str)
		ft_putendl_fd(str, 1);
	return (a);
}
