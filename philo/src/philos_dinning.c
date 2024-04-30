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

#include "../includes/philo.h"

void		philos_dinner(t_philo *philos, t_program *program);
static void	threads_create(t_philo *philos, pthread_t *monitoring,
				int philo_num);
static void	threads_create_await(t_program *p, pthread_t monitoring);
static void	*routine(void *philos);

/**
 * philos_call - create, join threads (philos).
 * @philos: pointer to philosophers
 * @program: pointer program
 * 
 * Return: void.
*/
void	philos_dinner(t_philo *philos, t_program *program)
{
	pthread_t	monitoring;

	if (program->num_of_times_to_eat == 0)
		mutex_destroy(program, "no dinner to eat!\n", 4, program->philo_num);
	if (program->philo_num == 1)
	{
		pthread_mutex_lock(&philos->first_fork->fork);
		print_msg("has taken a fork", philos);
		philos_syncro(program->time_to_die + 1);
		pthread_mutex_unlock(&philos->first_fork->fork);
		print_msg("died", philos);
		mutex_destroy(program, NULL, 4, program->philo_num);
		return ;
	}
	threads_create(philos, &monitoring, program->philo_num);
	threads_create_await(program, monitoring);
}

/**
 * threads_create - handle threads creation through pthread API
 * threads concerned are each philo thread and another thread
 * for monitoring the simulation.
 * @philos: pointer to philosophers
 * @monitoring: pointer to monitiring thread
 * @philo_num: number of philosophers
 * 
 * Return: void.
*/
static void	threads_create(t_philo *philos, pthread_t *monitoring,
				int philo_num)
{
	size_t		index;

	index = 0;
	if (pthread_create(monitoring, NULL, monitore, philos->program))
		mutex_destroy(philos->program, "Error creating monitoring thread!\n",
			4, philos->program->philo_num);
	while (index < (size_t)philo_num)
	{
		if (pthread_create(&philos->thread, NULL, routine, (void *)philos))
		{
			if (pthread_join(*monitoring, NULL))
				mutex_destroy(philos->program, "Error joining Moni thread\n",
					4, philos->program->philo_num);
			mutex_destroy(philos->program, "Error creating threads!\n",
				4, philos->program->philo_num);
		}
		index++;
		if (index < (size_t)philo_num)
			philos++;
	}
}

/**
 * threads_create_await - join all threads already created
 * to main thread; in order to wait for them.
 * @p: pontert to program
 * @monitoring: pointer to monitoring thread.
 * 
 * Return: void.
*/
static void	threads_create_await(t_program *p, pthread_t monitoring)
{
	int		philos_num;
	size_t	index;

	philos_num = p->philo_num;
	index = 0;
	if (pthread_join(monitoring, NULL))
		mutex_destroy(p, "Error: joining monitoring thread\n", 4, p->philo_num);
	while (index < (size_t)philos_num)
	{
		if (pthread_join(p->philos->thread, NULL))
			mutex_destroy(p, "Error: joining threads!\n", 4, p->philo_num);
		index++;
		p->philos++;
	}
	p->philos = p->philos - index;
}

/**
 * routine - recurrent routine of philos;
 * #estr "eat, sleep, think, repeat!".
 * @philos: pointer to philosophers
 * 
 * Return: void pointer.
*/
static void	*routine(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	if (p->id % 2 == 0)
		philos_syncro(1);
	while (dead_loop(philos) == false
		&& full_loop(philos) == false)
	{
		eating(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}
