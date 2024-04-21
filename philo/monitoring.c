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

#include "philo.h"

void			*monitore(void *program);
static void		monitor_checker(t_philo *philos);
static t_bool	death_checker(t_philo *philos);
static t_bool	full_checker(t_philo *philos, size_t *all_full);

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
	pthread_mutex_lock(&p->dead_lock); // data race between dead_loop (read) and monitor (write).
	p->simulation_end = true;
	pthread_mutex_unlock(&p->dead_lock);
	return (NULL);
}

/**
 * full_checker -
*/
static void	monitor_checker(t_philo *philos)
{
	size_t	index;
	size_t 	all_full;

	index = 0;
	all_full = 0;
	while (true)
	{
		// check for death
		if (death_checker(&philos[index]) == true)
			return ;
		// check for full
		if (full_checker(&philos[index], &all_full) == true)
			return ;
		index++;
		if (index == philos->program->philo_num)
		{
			all_full = 0;
			index = 0;
		}
	}
}

/**
 * death_checker -
*/
static t_bool	death_checker(t_philo *philos)
{
	size_t	time;

	// to read from last_meal_counter
	pthread_mutex_lock(philos->meal_lock);
	time = gettime(milliseconds) - (size_t)philos->last_meal_counter;
	pthread_mutex_unlock(philos->meal_lock);
	if (time > philos->program->time_to_die)
	{
		print_msg("philo dead", philos);
		return (true);
	}
	return (false);
}

/**
 * full_checker -
*/
static t_bool	full_checker(t_philo *philos, size_t *all_full)
{
	// prevent data race, read from full
	pthread_mutex_lock(philos->meal_lock);
	if (philos->number_of_meals_consumed == philos->program->num_of_times_to_eat)
	{
		pthread_mutex_lock(philos->full_lock);
		philos->full = true;
		pthread_mutex_unlock(philos->full_lock);
		*all_full = *all_full + 1;
	}
	pthread_mutex_unlock(philos->meal_lock);
	if (*all_full == philos->program->philo_num)
		return (true);
	return (false);
}
