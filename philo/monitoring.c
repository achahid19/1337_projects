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

/**
 * 
*/

/**
 * check if all philos are full
*/
t_bool	full_checker(t_philo *philos)
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
			return (true);
		index++;
		if (index == philos->program->philo_num)
		{
			all_full = 1;
			index = 0;
		}
	}
	return (false);
}


t_bool	death_checker(t_philo *philos)
{
	size_t	time;

	// to read from last_meal_counter
	pthread_mutex_lock(philos->meal_lock);
	time = gettime(milliseconds) - (size_t)philos->last_meal_counter;
	pthread_mutex_unlock(philos->meal_lock);
	if (time >= philos->program->time_to_die)
	{
		print_msg("philo dead", philos, true);
		return (true);
	}
	return (false);
}

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
		{
			printf("FULL\n");
			break;
		}
		if (death_checker(&philo[index]) == true)
			break;
		index++;
		if (index == p->philo_num)
			index = 0;
	}
	// write to simulation_end
	pthread_mutex_lock(&p->write_lock);
	pthread_mutex_lock(&p->dead_lock);
	p->simulation_end = true;
	pthread_mutex_unlock(&p->dead_lock);
	pthread_mutex_unlock(&p->write_lock);
	return (NULL);
}
