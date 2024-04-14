/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:10:11 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/12 14:10:12 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		philos_syncro(size_t milliseconds);
long		gettime(long time_code);

void	philos_syncro(size_t ms)
{
	size_t	start;

	start = gettime(milliseconds);
	while ((gettime(milliseconds) - start) < ms)
		usleep(500);
}

/**
 * gettime -
*/
long	gettime(long time_code)
{
	struct timeval	time_val;

	if (gettimeofday(&time_val, NULL))
		print_error("Error with timestamp fetch!\n");
	else if (time_code == milliseconds)
		return ((time_val.tv_sec * 1e3) + (time_val.tv_usec / 1e3));
	else if (time_code == microseconds)
		return ((time_val.tv_sec * 1e6) + time_val.tv_usec);
	else if (time_code == seconds)
		return (time_val.tv_sec + (time_val.tv_usec / 1e6));
	else
		print_error("Wrong input to gettime function!\n");
	return (1337);
}
