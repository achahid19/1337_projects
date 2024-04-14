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

void		philos_call(t_philo *philos, t_program *program);
static void	*routine(void *philos);
static void	threads_create(t_philo *philos, int philo_num);
static void	threads_create_await(t_program *p);

/**
 * philos_dinner_start -
*/
void	philos_call(t_philo *philos, t_program *program)
{
	if (program->num_of_times_to_eat == 0)
		print_error("no dinner to eat!\n");
	if (program->philo_num == 1)
		print_error("philos num is 1\n"); // TODO
	// create the threads
		// once the thread is created, philos start running
		// so I need synchronization between all philos
		// in a way they start simultaneously
	threads_create(philos, program->philo_num);
	threads_create_await(program); // TO EDIT
	philos = NULL;
}

t_bool	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->death == 1)
		return (pthread_mutex_unlock(&philo->philo_mutex), true);
	pthread_mutex_unlock(&philo->philo_mutex);
	return (false);
}

/**
 * routine -
 * wait all philos, syncro starts
*/
static void	*routine(void *philos)
{
	t_philo *p;

	p = (t_philo *)philos;
	(void)p;
	// make the even philos wait to avoid potential deadlock.
	if (p->id % 2)
		philos_syncro(1);
	printf("philo id: %d CREATED\n", p->id);
	/* printf("thread with id: %d CREATED\n", p->id); */
	while (dead_loop(philos) == false)
	{
		//eat
		//sleep
		//think
		// REAPET
	}
	//printf("CREATED\n");
	// philos pointer will be checked by the monitor
	return (p);
}

/**
 * threads_create
*/
static void	threads_create(t_philo *philos, int philo_num)
{
	size_t	index;

	index = 0;
	while (index < (size_t)philo_num)
	{
		if (pthread_create(&philos->thread, NULL, &routine, (void *)philos) != 0)
			print_error("Error creating threads!");
		index++;
		if (index < (size_t)philo_num)
			philos++;
	}
	// update the pointer.
	philos = NULL;
}

/**
 * dinner_await -
*/
static void	threads_create_await(t_program *p)
{
	int		philos_num;
	size_t	index;

	philos_num = p->philo_num;
	index = 0;
	while (index < (size_t)philos_num)
	{
		if (pthread_join(p->philos->thread, NULL) != 0)
			print_error("Error while joinning threads!\n");
		index++;
		p->philos++;
	}
	p->philos = p->philos - index;
}
