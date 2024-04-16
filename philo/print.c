/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:54 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:56:55 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(const char *error);
void	print_msg(char *msg, t_philo *philo, t_bool dead);

/**
 * print_error
*/
void	print_error(const char *error)
{
	write(2, error, ft_strlen(error));
	exit(-1);
}

/**
 * print_mgs
*/
void	print_msg(char *msg, t_philo *philo, t_bool dead)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (dead == false)
		time = gettime(milliseconds) - philo->simulation_start;
	else if (dead == true)
		time = gettime(milliseconds) - philo->last_meal_counter;
	if (philo->program->simulation_end == false)
		printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->write_lock);
}
