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
static t_bool	full_checker(t_philo *philos);
static t_bool	death_checker(t_philo *philos);

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
	size_t		index;

	p = (t_program *)program;
	index = 0;
	philo = p->philos;
	while (true)
	{
		if (full_checker(philo) == true)
			break;
		if (death_checker(&philo[index]) == true)
			break;
		index++;
		if (index == p->philo_num)
			index = 0;
	}
	pthread_mutex_lock(&p->write_lock); // data race between print_msg (read) and monitor (write).
	pthread_mutex_lock(&p->dead_lock); // data race between dead_loop (read) and monitor (write).
	p->simulation_end = true;
	pthread_mutex_unlock(&p->dead_lock);
	pthread_mutex_unlock(&p->write_lock);
	return (NULL);
}

/**
 * full_checker -
*/
static t_bool	full_checker(t_philo *philos)
{
	size_t	index;
	size_t 	all_full;

	index = 0;
	all_full = 1;
	while ((size_t)philos[index].id < philos->program->philo_num)
	{
		// prevent data race, read from full
		
		pthread_mutex_lock(philos->meal_lock);
		if (philos[index].full == true)
			all_full++;
		pthread_mutex_unlock(philos->meal_lock);
		if (all_full == philos->program->philo_num)
		{

			printf("full status: %ld\n", all_full);
			return (true);
		}
		index++;
		if (index == philos->program->philo_num)
		{
			all_full = 1;
			index = 0;
		}
	}
	return (false);
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
	if (time >= philos->program->time_to_die)
	{
		print_msg("philo dead", philos);
		return (true);
	}
	return (false);
}
