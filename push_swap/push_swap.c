/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:12:34 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/18 13:12:35 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_main_stack(stack_ptr a)
{
	stack_ptr	tmp;

	tmp = a;
	while (tmp != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
		tmp = a->next;
	}
	free(a);
	printf("done");
}

void	main_stack_fill(stack_ptr a, char **args)
{
	stack_ptr	new;
	stack_ptr	tmp;
	
	while (*args != NULL)
	{
		new = malloc(sizeof(t_stack_node));
		/* if (NULL == new)
		{
			if (a != NULL)
				
		} */
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
	free_main_stack(a);
	/* Now the linked list is created, need to check for duplicates! */
	/* have to free the main stack when I finish with it */
}

/**
 * main - Entry point of the program
 * Description: Sorting numbers "arguments" on the stack in ascending order
 * 
 * Return: Always 0 (Success).
*/
int	main(int argc, char *argv[])
{
	stack_ptr	a;
	stack_ptr	b;
	char		**args;

	a = NULL;
	b = NULL;
	if (argc <= 1 || NULL == argv[1]) // lack of args, only program name!
		exit(0); // program succeed but does nothing

	/* Now I have to check the arguments */
	args = args_checker(argv + 1);
	/* Now, must check for duplicates in the 2D array */
	// in order to check, have to convert the strings into integers
		// then after we had our integers, we can compare them
		// If any of them is equal to the other, then exit().
	/* fill the stack a with the corresponding args */
	main_stack_fill(a, args);
	return (0);
}
