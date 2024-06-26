/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:38 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:56:40 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * main - Entry point
 * Description: the main is a TL;DR of the program
 * ./a.out 5(philo_num) 800(time_to_die) \ 
 * 200 time_to_eat) 100(time_to_sleep) [6](optional) \
 * (max_number_of_meals).
 * 
 * Return: Always 0 (Success).
*/
int	main(int ac, char *av[])
{
	t_philo		philos[PHILO_LIMIT];
	t_fork		forks[PHILO_LIMIT];
	t_program	program;

	if (ac < 5 || ac > 6 || check_inputs(av) == false)
	{
		print_error("Invalid input!\n");
		return (failure);
	}
	if (init_data(philos, forks, &program, av) == false)
		return (failure);
	if (philos_dinner(philos, &program) == false)
		return (failure);
	if (mutex_destroy(&program, NULL, 4, program.philo_num) == false)
		return (failure);
	return (0);
}
