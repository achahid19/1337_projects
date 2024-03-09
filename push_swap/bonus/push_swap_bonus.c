/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:35:23 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 10:35:24 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

/**
 * main - Entry point
 * Description: read the instructions given by push_swap
 * program to sort the values on a stack, if the
 * instructions readed from stdin, they sort
 * our stack, the checker program prints on stdout
 * 'OK', otherwise it prints 'KO'
 * @ac: argument counts
 * @av: double pointer to the values to sort on a stack
 * Return: Always 0 (Success).
*/
int	main(int ac, char *av[])
{
	t_stack_ptr	a;
	t_stack_ptr	b;
	char		**args;
	char		**actions;

	a = NULL;
	b = NULL;
	if (av[1] == NULL || *av[1] == '\0' || ac == 1)
		exit(0);
	args = args_checker(av + 1);
	main_stack_build(args, &a);
	actions = read_instructions(a, args);
	a = actions_search_execute(a, &b, actions, args);
	if (true == is_sorted(a) && b == NULL)
		write(1, "OK\n", ft_strlen("OK\n"));
	else
	{
		if (b != NULL)
			free_stack(b);
		free_all(args, a, actions);
		exit_error("KO\n", 1);
	}
	free_all(args, a, actions);
	return (0);
}
