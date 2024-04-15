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

#include "philo.h"


void	mutex_destroy(t_program *p, t_fork *forks)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&p->dead_lock);
	pthread_mutex_destroy(&p->meal_lock);
	pthread_mutex_destroy(&p->write_lock);
	while (i < p->philo_num)
	{
		pthread_mutex_destroy(&forks->fork);
		i++;
	}
}

/**
 * main - Entry point
 * Description: the main is a TL;DR of the program
 * ./a.out 5 800 190 200 [6]
 * 
 * Return: Always 0 (Success).
*/
int	main(int ac, char *av[])
{
	t_philo		philos[PHILO_LIMIT];
	t_fork		forks[PHILO_LIMIT];
	t_program	program;

	if (ac < 5 || ac > 6 || check_inputs(av) == false)
		print_error("Invalid input!\n");
	// init_data().
	init_data(philos, forks, &program, av);
	// threads creation
	philos_call(philos, &program);
	// Simulation (dinner) starting
	mutex_destroy(&program, forks);

	return (0);
}
