/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:54:13 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/14 11:54:17 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void			*monitore(void *program);
static void		monitor_checker(t_philo *philos);
static t_bool	death_checker(t_philo *philos);
void			*full_checker(void *philos);
static void		full_check_helper(t_philo *philos, int *all_full);

/**
 * monitore - monitoring philos dinner
 * simulation, checks for philo death
 * or philos are full (eaten all what they
 * have to).
 * @program: pointer to program.
 * 
 * Return: void pointer.
*/
void	*monitore(void *program)
{
	t_program	*p;
	t_philo		*philo;

	p = (t_program *)program;
	philo = p->philos;
	monitor_checker(philo);
	return (NULL);
}

/**
 * full_checker -
*/
static void	monitor_checker(t_philo *philos)
{
	size_t		index;
	pthread_t	full_monitor;

	index = 0;
	if (pthread_create(&full_monitor, NULL, full_checker, philos))
		mutex_destroy(philos->program, "Error: create full monitor thread\n",
			4, philos->program->philo_num);
	while (philos->program->simulation_end == false)
	{
		if (death_checker(&philos[index]) == true)
			break ;
		index++;
		if (index == philos->program->philo_num)
			index = 0;
	}
	pthread_mutex_lock(philos->dead_lock);
	philos->program->simulation_end = true;
	pthread_mutex_unlock(philos->dead_lock);
	if (pthread_join(full_monitor, NULL))
		mutex_destroy(philos->program, "Error: create full monitor thread\n",
			4, philos->program->philo_num);
}

/**
 * death_checker -
*/
static t_bool	death_checker(t_philo *philos)
{
	size_t	time;

	pthread_mutex_lock(philos->meal_lock);
	time = gettime(milliseconds) - (size_t)philos->last_meal_counter;
	pthread_mutex_unlock(philos->meal_lock);
	pthread_mutex_lock(philos->full_lock);
	if (time > philos->program->time_to_die
		&& philos->full == false)
	{
		pthread_mutex_unlock(philos->full_lock);
		print_msg("died", philos);
		return (true);
	}
	pthread_mutex_unlock(philos->full_lock);
	return (false);
}

/**
 * full_checker -
*/
void	*full_checker(void *p)
{
	t_philo	*philos;
	size_t	i;
	int		all_full;

	philos = (t_philo *)p;
	i = 0;
	all_full = 0;
	while (i < philos->program->philo_num
		&& philos->program->simulation_end == false)
	{
		full_check_helper(&philos[i], &all_full);
		i++;
		if ((size_t)all_full == philos->program->philo_num)
			break ;
		if (i == philos->program->philo_num)
			i = 0;
	}
	pthread_mutex_lock(philos->dead_lock);
	philos->program->simulation_end = true;
	pthread_mutex_unlock(philos->dead_lock);
	return (NULL);
}

/**
 * full_check_helper -
*/
static void	full_check_helper(t_philo *philos, int *all_full)
{
	pthread_mutex_lock(philos->meal_lock);
	if (philos->number_of_meals_consumed
		== philos->program->num_of_times_to_eat)
	{
		pthread_mutex_lock(philos->full_lock);
		if (philos->full == false)
			*all_full = *all_full + 1;
		philos->full = true;
		pthread_mutex_unlock(philos->full_lock);
	}
	pthread_mutex_unlock(philos->meal_lock);
}
