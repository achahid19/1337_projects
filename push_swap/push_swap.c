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
 * is_sorted - checks if the values on the stack are sorted
 * @a: pointer to the stack to check
 * Return: fasle if it's not sorted, otherwise true
*/
bool	is_sorted(stack_ptr a)
{
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return (false);
		a = a->next;
	}
	return (true);
}

/**
 * swap - executes a swap between the 2 values on the top of the stack
 * @a: pointer to the stack
 * @str: pointer to the operation to execute
 * Return: void.
 * 
*/
void	swap(stack_ptr a, char *str)
{
	int	tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
	tmp = a->index;
	a->index = a->next->index;
	a->next->index = tmp;
	if (str)
		printf("%s\n", str);
}

/**
 * push_swap - sort values in ascending order with a minimum of
 * actions to execute.
 * @a: pointer to the main stack
 * @b: pointer to the assisting stack
 * @size: size of the main stack
 * Return: void.
*/
void	push_swap(stack_ptr a, stack_ptr b, size_t size)
{
	if (2 == size && false == is_sorted(a))
		swap(a, "sa");
}

/**
 * for memory allocation, still have (stack a) + pointer to args (**args)
*/

// TODO
	// try to sort two values and implement 'sa' operation

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
	push_swap(a, b, stack_size);
	stack_ptr tmp;
	for (tmp = a; tmp != NULL; tmp = tmp->next)
		printf("%d\n", tmp->num);
	free_main_stack(a);
	return (0);
}
