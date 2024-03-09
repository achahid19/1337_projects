/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:11:59 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/09 15:12:01 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_bool	stack_a_actions(char *action, t_stack_ptr *a, t_stack_ptr *b,
			t_bool action_checker);
t_bool	stack_b_actions(char *action, t_stack_ptr *b, t_stack_ptr *a,
			t_bool action_checker);
t_bool	both_stack_actions(char *action, t_stack_ptr *a, t_stack_ptr *b,
			t_bool action_checker);
void	free_stack(t_stack_ptr stack);

/**
 * stack_a_actions
*/
t_bool	stack_a_actions(char *action, t_stack_ptr *a, t_stack_ptr *b,
			t_bool action_checker)
{
	if (!ft_strncmp(action, "sa", 3))
	{
		action_checker = true;
		swap((*a));
	}
	else if (!ft_strncmp(action, "ra", 3))
	{
		action_checker = true;
		(*a) = rotate((*a));
	}
	else if (!ft_strncmp(action, "rra", 4))
	{
		action_checker = true;
		(*a) = rev_rotate((*a));
	}
	else if (!ft_strncmp(action, "pa", 3))
	{
		action_checker = true;
		(*a) = push((*a), b, "pa");
	}
	return (action_checker);
}

/**
 * stack_b_actions
*/
t_bool	stack_b_actions(char *action, t_stack_ptr *b, t_stack_ptr *a,
			t_bool action_checker)
{
	if (!ft_strncmp(action, "sb", 3))
	{
		action_checker = true;
		swap((*b));
	}
	else if (!ft_strncmp(action, "rb", 3))
	{
		action_checker = true;
		*b = rotate((*b));
	}
	else if (!ft_strncmp(action, "rrb", 4))
	{
		action_checker = true;
		*b = rev_rotate((*b));
	}
	else if (!ft_strncmp(action, "pb", 3))
	{
		action_checker = true;
		(*a) = push((*a), b, "pb");
	}
	return (action_checker);
}

/**
 * both_stack_actions
*/
t_bool	both_stack_actions(char *action, t_stack_ptr *a, t_stack_ptr *b,
			t_bool action_checker)
{
	if (!ft_strncmp(action, "rr", 3))
	{
		action_checker = true;
		(*a) = rotate_both_stack((*a), b);
	}
	else if (!ft_strncmp(action, "rrr", 4))
	{
		action_checker = true;
		(*a) = rev_rotate_both_stack((*a), b);
	}
	else if (!ft_strncmp(action, "ss", 3))
	{
		action_checker = true;
		swap_both((*a), b);
	}
	return (action_checker);
}

/**
 * free_stack - frees all the nodes building the linked list of the stack
 * @a: pointer to stack
 * Return: void.
*/
void	free_stack(t_stack_ptr stack)
{
	t_stack_ptr	tmp;

	if (NULL == stack)
		return ;
	tmp = stack;
	if (NULL == tmp->next)
	{
		free(stack);
		return ;
	}
	while (tmp != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}
