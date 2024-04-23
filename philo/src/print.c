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

#include "../includes/philo.h"

void	print_error(const char *error);
void	print_msg(char *msg, t_philo *philo);
void	destroy_print_error(const char *error, t_program *p, t_fork *forks);

/**
 * print_error
*/
void	print_error(const char *error)
{
	if (error == NULL)
		return ;
	write(2, error, ft_strlen(error));
	exit(-1);
}

/**
 * destroy_print_error -
*/
/* void	destroy_print_error(const char *error, t_program *p, t_fork *forks)
{
	mutex_destroy(p, forks);
	print_error(error);
} */

/**
 * print_mgs -
*/
void	print_msg(char *msg, t_philo *philo)
{
	size_t	time;

	time = gettime(milliseconds) - philo->simulation_start;
	pthread_mutex_lock(philo->dead_lock);
	if (philo->program->simulation_end == false)
		printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->dead_lock);
}