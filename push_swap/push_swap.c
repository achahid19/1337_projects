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
		exit(0);

	args = args_checker(argv + 1); // Do NOT FORGET TO FREES THE ARGS WHEN DONE
	a = main_stack_build(args);
	free_args(args);
	free_main_stack(a);
	return (0);
}
