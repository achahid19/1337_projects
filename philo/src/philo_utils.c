/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:20:07 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/23 10:20:09 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool			mutex_destroy(t_program *p, char *error,
					int destroy_code, int destroy_index);
static t_bool	mutex_destroy_helper(t_program *p, char *error,
					int di, int destroy_code);
t_bool			dead_loop(t_philo *philo);
t_bool			full_loop(t_philo *philo);
void			join_all(t_philo *philos, size_t index,
					pthread_t *monitoring);

/**
 * mutex_destroy - clear all initialized mutexes
 * @p: pointer to program data list
 * @forks: pointer to forks list
 * 
 * Return: void.
*/
t_bool	mutex_destroy(t_program *p, char *error,
			int destroy_code, int destroy_index)
{
	if (destroy_code == 0)
		print_error(error);
	else if (destroy_code == 1)
	{
		if (pthread_mutex_destroy(&p->dead_lock))
			return (print_error("Error: mutex destroy!"), false);
		print_error(error);
	}
	else if (destroy_code == 2)
	{
		if (pthread_mutex_destroy(&p->dead_lock))
			return (print_error("Error: mutex destroy!"), false);
		if (pthread_mutex_destroy(&p->meal_lock))
			return (print_error("Error: mutex destroy!"), false);
		print_error(error);
	}
	else if (destroy_code == 4 || destroy_code == 3)
	{
		if (mutex_destroy_helper(p, error, destroy_index, destroy_code)
			== false)
			return (false);
	}
	return (true);
}

/**
 * mutex_destroy_helper -
*/
static t_bool	mutex_destroy_helper(t_program *p, char *error,
			int di, int destroy_code)
{
	int	i;

	i = 0;
	if (destroy_code == 3 || destroy_code == 4)
	{
		if (pthread_mutex_destroy(&p->dead_lock))
			return (print_error("Error: mutex destroy!"), false);
		if (pthread_mutex_destroy(&p->meal_lock))
			return (print_error("Error: mutex destroy!"), false);
		if (pthread_mutex_destroy(&p->write_lock))
			return (print_error("Error: mutex destroy!"), false);
		if (destroy_code == 3)
			return (print_error(error), true);
	}
	if (pthread_mutex_destroy(&p->full_lock))
		return (print_error("Error: mutex destroy!"), false);
	while (i < di)
	{
		if (pthread_mutex_destroy(&p->forks[i].fork))
			return (print_error("Error: mutex destroy!"), false);
		i++;
	}
	print_error(error);
	return (true);
}

/**
 * dead_loop - checks continueously for
 * a philosopher death.
 * @philo: pointer to philosophers
 * 
 * Return: state of life; true if death, else false.
*/
t_bool	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->program->simulation_end == true)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	return (pthread_mutex_unlock(philo->dead_lock), false);
}

/**
 * full_loop -
*/
t_bool	full_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->full_lock);
	if (philo->full == true)
		return (pthread_mutex_unlock(philo->full_lock), true);
	return (pthread_mutex_unlock(philo->full_lock), false);
}

/**
 * join_all - join created thread if a thread fails
*/
void	join_all(t_philo *philos, size_t index, pthread_t *monitoring)
{
	size_t	join;

	join = 0;
	pthread_join(*monitoring, NULL);
	while (join < index)
	{
		pthread_join(philos[join].thread, NULL);
		join++;
	}
}
