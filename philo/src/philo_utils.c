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

void		mutex_destroy(t_program *p, char *error,
				int destroy_code, int destroy_index);
void		mutex_destroy_helper(t_program *p, char *error,
				int di);

/**
 * mutex_destroy - clear all initialized mutexes
 * @p: pointer to program data list
 * @forks: pointer to forks list
 * 
 * Return: void.
*/
void	mutex_destroy(t_program *p, char *error,
			int destroy_code, int destroy_index)
{
	if (destroy_code == 0)
		print_error(error);
	else if (destroy_code == 1)
	{
		pthread_mutex_destroy(&p->dead_lock);
		print_error(error);
	}
	else if (destroy_code == 2)
	{
		pthread_mutex_destroy(&p->dead_lock);
		pthread_mutex_destroy(&p->meal_lock);
		print_error(error);
	}
	else if (destroy_code == 3)
	{
		pthread_mutex_destroy(&p->dead_lock);
		pthread_mutex_destroy(&p->meal_lock);
		pthread_mutex_destroy(&p->write_lock);
		print_error(error);
	}
	else if (destroy_code == 4)
		mutex_destroy_helper(p, error, destroy_index);
}

/**
 * mutex_destroy_helper -
*/
void	mutex_destroy_helper(t_program *p, char *error,	int di)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&p->dead_lock);
	pthread_mutex_destroy(&p->meal_lock);
	pthread_mutex_destroy(&p->write_lock);
	pthread_mutex_destroy(&p->full_lock);
	while (i < di)
	{
		pthread_mutex_destroy(&p->forks[i].fork);
		i++;
	}
	print_error(error);
}
