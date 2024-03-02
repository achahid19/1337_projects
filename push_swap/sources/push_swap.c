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

#include "../includes/push_swap.h"

static stack_ptr	push_swap(stack_ptr a, stack_ptr *b, size_t size);
static stack_ptr	sortof3(stack_ptr a);
static stack_ptr	sort_big_stack(stack_ptr a, stack_ptr *b, size_t size_a);

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
	if (argc <= 1 || NULL == argv[1])
		exit(0);
	args = args_checker(argv + 1);
	a = main_stack_build(args);
	free_args(args);
	stack_size = get_stack_size(a);
	stack_indexing(a, stack_size + 1);
	a = push_swap(a, &b, stack_size);
	free_main_stack(a);
	return (0);
}

/**
 * push_swap - sort values in ascending order with a minimum number of
 * actions to execute.
 * @a: pointer to the main stack
 * @b: pointer to the assisting stack
 * @size: size of the main stack
 * Return: void.
*/
static stack_ptr	push_swap(stack_ptr a, stack_ptr *b, size_t size)
{
	if (2 == size && false == is_sorted(a))
		swap(a, "sa");
	else if (3 == size && false == is_sorted(a))
		a = sortof3(a);
	else if (size > 3 && false == is_sorted(a))
		a = sort_big_stack(a, b, size);
	return (a);
}

/**
 * sorfOf3 - executes an algorithm to sort 3 values on the top of the stack,
 * @a: pointer to the main stack
 * Return: pointer to head (first node on the stack)
*/
static stack_ptr	sortof3(stack_ptr a)
{
	size_t	highest;

	highest = find_hindex(a);
	if (a->index == highest)
		a = rotate(a, "ra");
	else if (a->next->index == highest)
		a = rev_rotate(a, "rra");
	if (false == is_sorted(a))
		swap(a, "sa");
	return (a);
}

/**
 * sort_big_stack - Using a adequat sorting algorithm to sort the stack
 * firstly, based on the mediane of the stack size, we push the lowest
 * indexes below the median to stack b, saveof3() function handles the
 * operations and save 3 elements on stack a (main stack) that will
 * be sorted with sortof3().
 * Then we iterate over stack b until its pointing to NULL; will iterating
 * over each element, a target position is assigned to the element which
 * help us to know the position of B element in the main stack (a).
 * This target position will be used to calculate ca and cb, then
 * depending on ca and cb, we gonna move both stacks then push
 * B elements to stack a.
 * Finally, if stack a is not yet sorted, shifting the stack is needed.
 * stack_shifting(), search for the position of the lowest index on the
 * stack then shift it until the lowest index hit the top of the stack.
 * @a: pointer to the main stack (a)
 * @b: double pointer to the temporary stack (b)
 * @size_a: size of main stack (a).
 * Return: pointer to the main stack (a).
*/
static stack_ptr	sort_big_stack(stack_ptr a, stack_ptr *b, size_t size_a)
{
	a = saveof3(a, b, size_a);
	a = sortof3(a);
	while ((*b) != NULL)
	{
		target_pos(a, b);
		cost_get(a, b);
		a = lowest_cost_move(a, b);
	}
	if (false == is_sorted(a))
		a = stack_shifting(a);
	return (a);
}
