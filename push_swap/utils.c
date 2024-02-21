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


static void	free_main_stack(stack_ptr a);

/**
 * main_stack_fill - build the stack which will contains all the metadata needed
 * @a: pointer to stack a (main stack)
 * @args: pointer to arguments which will be sorted on the stack
 * Return: void.
*/
void	main_stack_fill(stack_ptr a, char **args)
{
	stack_ptr	new;
	stack_ptr	tmp;
	
	while (*args != NULL)
	{
		new = malloc(sizeof(t_stack_node));
		if (NULL == new)
		{
			free_main_stack(a);
			exit(-1); // TODO error handling. + perror.
		}
		new->num = ft_atoi(*args);
		new->next = NULL;
		if (NULL == a)
			a = new;
		else
		{
			tmp = a;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			if (tmp->next == NULL)
				tmp->next = new;
		}
		args++;
	}
	tmp = a;
	while (tmp != NULL) // print the stack for test purposes
	{
		printf("%ld\n", tmp->num);
		tmp = tmp->next;
	}
	/* Now the linked list is created, need to check for duplicates! */
	/* have to free the main stack when I finish with it */
	free_main_stack(a);
}

/**
 * free_main_stack - frees all the nodes building the linked list of the stack a
 * @a: pointer to stack a (main stack)
 * Return: void.
*/
static void	free_main_stack(stack_ptr a)
{
	stack_ptr	tmp;

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
