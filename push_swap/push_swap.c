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

/**
 * for memory allocation, still have (stack a) + pointer to args (**args)
*/

// TODO
	// indexing each node depending on the value of num, going from 1 to n,
	// in an ascending order depending on num.
	// e.g 100 29 19, 3 2 1

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
	size_t		stack_size;
	char		**args;

	a = NULL;
	b = NULL;
	if (argc <= 1 || NULL == argv[1]) // lack of args, only program name!
		exit(0);

	args = args_checker(argv + 1); // Do NOT FORGET TO FREES THE ARGS WHEN DONE
	a = main_stack_build(args);
	free_args(args);
	// After we passing all checks, now build the main stack
	stack_size = get_stack_size(a);
	stack_indexing(a, stack_size + 1);
	// now the sort will be done by index, we know which value is 1 (lowest) and which one is stack_size (highest)
	stack_ptr	tmp;
	for (tmp = a; tmp != NULL; tmp = tmp->next)
	{
		printf("num: %d for index => %lu\n", tmp->num, tmp->index);
	}
	free_main_stack(a);
	return (0);
}
