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

#include "push_swap.h"


void		free_main_stack(stack_ptr a);
void		free_args(char **args);
size_t		get_stack_size(stack_ptr stack);
void		stack_indexing(stack_ptr stack_a, int size);
static void	node_init(stack_ptr *new, char **args);


static void	node_init(stack_ptr *new, char **args)
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
 * main_stack_fill - build the stack which will contains all the metadata needed
 * @a: pointer to stack a (main stack)
 * @args: pointer to arguments which will be sorted on the stack
 * Return: void.
*/
stack_ptr	main_stack_build(char **args)
{
	stack_ptr	new;
	stack_ptr	tmp;
	stack_ptr	a;
	
	a = NULL;
	while (*args != NULL)
	{
		new = malloc(sizeof(t_stack_node));
		if (NULL == new)
			free_and_exit(a, args);
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
	/* Now the linked list is created, need to check for duplicates! */
	/* have to free the main stack when I finish with it */
	return (a);
}

/**
 * free_main_stack - frees all the nodes building the linked list of the stack
 * @a: pointer to stack
 * Return: void.
*/
void	free_main_stack(stack_ptr a)
{
	stack_ptr	tmp;

	if (NULL == a)
		return ;
	tmp = a;
	/* In case we have only one node to free */
	if (NULL == tmp->next)
	{
		free(a);
		return ;
	}
	/* in case of a linked list of nodes */
	while (tmp != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
		tmp = a->next;
	}
	free(a);
	return ;
}

/**
 * free_args - freed all memory allocated to arguments
 * @args: pointer to arguments
 * Return: void.
*/
void	free_args(char **args)
{
	size_t	index;

	index = 0;
	while (args[index] != NULL)
	{
		free(args[index]);
		index++;
	}
	free(args);
	return ;
}

/**
 * get_stack_size - counts number of nodes on the stack
 * @stack: pointer to the stack
 * Return: stack's size
*/
size_t	get_stack_size(stack_ptr stack)
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
void	stack_indexing(stack_ptr stack_a, int size)
{
	stack_ptr	ptr;
	stack_ptr	highest_node;
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
