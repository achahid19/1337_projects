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

#include "../includes/philo.h"

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/**
 * eating - handle a philosopher eating
 * @philo: pointer to the concerned philosopher
 * 
 * Return: void.
*/
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(philo->meal_lock);
	print_msg("is eating", philo);
	philo->last_meal_counter = gettime(milliseconds);
	philo->number_of_meals_consumed++;
	pthread_mutex_unlock(philo->meal_lock);
	philos_syncro(philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->second_fork->fork);
	pthread_mutex_unlock(&philo->first_fork->fork);
}

/**
 * sleeping - philosopher sleeping time
 * @philo: pointer to concerned philosopher
 * 
 * Return: void.
*/
void	sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo);
	philos_syncro(philo->program->time_to_sleep);
}

/**
 * thinking - philosopher is thinking
 * @philo: pointer to concerned philosopher
 * 
 * Return: void.
*/
void	thinking(t_philo *philo)
{
	print_msg("is thinking", philo);
}
