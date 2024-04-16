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

void	mutex_destroy(t_program *p, t_fork *forks);

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
		print_error("Invalid input!\n");
	init_data(philos, forks, &program, av);
	philos_dinner(philos, &program);
	mutex_destroy(&program, forks);

	return (0);
}

/**
 * mutex_destroy - clear all initialized mutexes
 * @p: pointer to program data list
 * @forsk: pointer to forks list
 * 
 * Return: void.
*/
void	mutex_destroy(t_program *p, t_fork *forks)
{
	size_t	i;

	i = 0;
	if (&p->dead_lock != NULL)
		pthread_mutex_destroy(&p->dead_lock);
	if (&p->meal_lock != NULL)
		pthread_mutex_destroy(&p->meal_lock);
	if (&p->write_lock != NULL)
		pthread_mutex_destroy(&p->write_lock);
	while (i < p->philo_num)
	{
		if (&forks->fork != NULL)
			pthread_mutex_destroy(&forks->fork);
		i++;
	}
}
