/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:46:54 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/14 09:46:55 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, t_philo *philo)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	time = gettime(milliseconds) - philo->simulation_start;
	if (philo->program->simulation_end == false) // philo not dead
		printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

/**
 * 
*/
void	eating(t_philo *philo)
{
	if (philo->full == false)
	{
		pthread_mutex_lock(&philo->first_fork->fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(&philo->second_fork->fork);
		print_msg("has taken a fork", philo);
		// Start eating since this philo had 2 chopsticks.
		pthread_mutex_lock(philo->meal_lock);
		// needed for monitoring (current time - last_meal).
		philo->last_meal_counter = gettime(milliseconds);
		philo->number_of_meals_consumed++;
		if (philo->number_of_meals_consumed == philo->program->num_of_times_to_eat)
			philo->full = true;
		pthread_mutex_unlock(philo->meal_lock);
		print_msg("is eating", philo);
		philos_syncro(philo->program->time_to_eat);
		pthread_mutex_unlock(&philo->second_fork->fork);
		pthread_mutex_unlock(&philo->first_fork->fork);
	}
}

/**
 * 
*/
void	sleeping(t_philo *philo)
{
	print_msg("is seelping", philo);
	philos_syncro(philo->program->time_to_sleep);
}

/**
 *
*/
void	thinking(t_philo *philo)
{
	print_msg("is thinking", philo);
}
