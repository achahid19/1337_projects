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

#include "push_swap_bonus.h"

/**
 * 
*/
int	main(int ac, char *av[])
{
	t_stack_ptr	a;
	t_stack_ptr	b;
	char		**args;
	char		**actions;

	a = NULL;
	b = NULL;
	if (av[1] == NULL || *av[1] == '\0' || ac > 2)
		exit(0);
	if (false == args_checker(av[1]))
		exit_error("Error\n", 2);
	args = ft_split(av[1], ' ');
	args_duplicates_checker(args);
	main_stack_build(args, &a);
	actions = read_instructions(a, args);
	a = actions_search_execute(a, &b, actions);
	if (true == is_sorted(a))
		write(1, "OK\n", 3);
	else
	{
		free_all(args, a, actions);
		exit_error("KO\n", 1);
	}
	free_all(args, a, actions);
	return (0);
}
