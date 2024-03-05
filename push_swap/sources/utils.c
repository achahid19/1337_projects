/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:03:59 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/21 10:04:00 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_ptr	main_stack_build(t_stack_ptr a, char **args);
static void	node_init(t_stack_ptr *new, char **args);
size_t		get_stack_size(t_stack_ptr stack);
void		stack_indexing(t_stack_ptr stack_a, int size);
static void	node_init(t_stack_ptr *new, char **args);

/**
 * main_stack_fill - build the stack which will contains all the data needed
 * @a: pointer to stack a (main stack)
 * @args: pointer to arguments which will be sorted on the stack
 * Return: void.
*/
t_stack_ptr	main_stack_build(t_stack_ptr a, char **args)
{
	t_stack_ptr	new;
	t_stack_ptr	tmp;
	char		**ptr_args;

	a = NULL;
	ptr_args = args;
	while (*args != NULL)
	{
		new = malloc(sizeof(t_stack_node));
		if (NULL == new)
			free_and_exit(a, ptr_args);
		node_init(&new, args);
		if (NULL == a)
			a = new;
		else
		{
			tmp = a;
			while (tmp->next != NULL)
				tmp = tmp->next;
			if (tmp->next == NULL)
				tmp->next = new;
		}
		args++;
	}
	return (a);
}

/**
 * node_init - initialize the variables of the new node
 * created to be added to the stack
 * @new: pointer to the new created element
 * @args: double pointer to arguments
 * Return: void.
*/
static void	node_init(t_stack_ptr *new, char **args)
{
	(*new)->num = ft_atoi(*args);
	(*new)->index = 0;
	(*new)->pos = -1;
	(*new)->target_pos = -1;
	(*new)->ca = -1;
	(*new)->cb = -1;
	(*new)->next = NULL;
}

/**
 * get_stack_size - counts number of nodes on the stack
 * @stack: pointer to the stack
 * Return: stack's size
*/
size_t	get_stack_size(t_stack_ptr stack)
{
	size_t	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/**
 * stack_indexing - Assigns an index for each value in the main stack (a);
 * the indexing is done in ascending order, so the lowest value get index 1
 * and the highest get the size of the stack.
 * @stack_a: pointer to the main stack (a)
 * @size: size of stack
 * Return: void.
*/
void	stack_indexing(t_stack_ptr stack_a, int size)
{
	t_stack_ptr	ptr;
	t_stack_ptr	highest_node;
	int			num;

	while (--size > 0)
	{
		ptr = stack_a;
		highest_node = NULL;
		num = INT_MIN;
		while (ptr != NULL)
		{
			if (INT_MIN == ptr->num && 0 == ptr->index)
				ptr->index = 1;
			if (ptr->num > num && 0 == ptr->index)
			{
				num = ptr->num;
				highest_node = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest_node != NULL)
			highest_node->index = size;
	}
}
