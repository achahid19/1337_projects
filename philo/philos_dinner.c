/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:57:49 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/11 16:57:53 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		philos_call(t_philo *philos);
static void	*routine(void *philos);
static void	threads_create(t_philo *philos);
static void	threads_create_await(t_philo *philos);

/**
 * philos_dinner_start -
*/
void	philos_call(t_philo *philos)
{
	if (philos->num_of_times_to_eat == 0)
	// check if optional arg num_of_times_to_eat variable is not 0
		print_error("no dinner to eat!\n");
	// check there is only one philosopher
	if (philos->philo_num == 1)
		print_error("philos num is 1\n"); // TODO
	// create the threads
	threads_create(philos);
	// Start Monitoring dinner
	/* monitor_call(); */
	// wait for all threads to be created
	threads_create_await(philos);

	philos = NULL;
	return ;
}

/**
 * routine -
*/
static void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	printf("thread created id: %d\n", philo->id);
	return (NULL);
}

/**
 * threads_create
*/
static void	threads_create(t_philo *philos)
{
	size_t	index;

	index = 0;
	while (index < philos->philo_num)
	{
		if (pthread_create(&philos->thread, NULL, &routine, (void *)philos) != 0)
			print_error("Error creating threads!");
		index++;
		philos->threads_ready = true;
		if (index < philos->philo_num)
			philos++;
	}
	philos = NULL;
}

/**
 * dinner_await -
*/
static void	threads_create_await(t_philo *philos)
{
	int		philos_num;
	size_t	index;

	philos_num = philos->philo_num;
	index = 0;
	while (index < (size_t)philos_num)
	{
		if (pthread_join(philos->thread, NULL) != 0)
			print_error("Error while joinning threads!\n");
		index++;
		philos++;
	}
	philos = NULL;
}
