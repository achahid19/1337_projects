/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:38 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:57:39 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void		init_data(t_philo *philos, t_fork *forks, char *args[]);
static void	init_args(t_philo *philos_ptr, char *args[], int pnum);
static void	init_forks(t_fork *forks, t_philo *philos, int pnum);

/**
 * init_data - initialize the data related to each philosopher
 * @philos: pointer to data stucture of all philos
 * @forks: pointer to date stucture of all forks
 * @args: double pointer to program's arguments
 * 
 * Return: void.
*/
void	init_data(t_philo *philos, t_fork *forks, char *args[])
{
	int	i;
	int philos_number;

	i = 0;
	philos_number = ft_atol(args[1]);
	init_forks(forks, philos, philos_number);
	while (i < philos_number)
	{
		philos->id = i + 1;
		philos->full = false;
		philos->last_meal_counter = 0;		
		philos->number_of_meals_consumed = 0;
		init_args(philos, args, philos_number);
		if (i < philos_number - 1)
			philos->left_fork = ++philos->forks;
		else
			philos->left_fork = philos->forks - i;
/* 		printf("in call: %d, for philo id: %d, left fork is %d and right fork \
		is: %d\n", i, philos->id, philos->left_fork->fork_id, philos->right_fork->fork_id); */
		i++;
		philos++;
		forks++;
	}
}

/**
 * init_args - initialize the data related to
 * program's arguments
 * usleep() function accept only micro-seconds, for that
 * we times 1e3 to get milliseconds
 * @philos_ptr: pointer to data stucture of all philos
 * @args: double pointer to program's arguments
 * @pnum: number of philosophers
 * 
 * Return: void.
*/
static void	init_args(t_philo *philos_ptr, char *args[], int pnum)
{
	philos_ptr->philo_num = pnum;
	philos_ptr->time_to_die = ft_atol(args[2]) * 1e3;
	philos_ptr->time_to_eat = ft_atol(args[3]) * 1e3;
	philos_ptr->time_to_sleep = ft_atol(args[4]) * 1e3;
	philos_ptr->simulation_end = false;	
	philos_ptr->simulation_start = 0;
	if (args[5])
		philos_ptr->num_of_times_to_eat = ft_atol(args[5]);
	else
		philos_ptr->num_of_times_to_eat = -1;
	if (philos_ptr->time_to_die <= 6e4 ||
		philos_ptr->time_to_eat <= 6e4 ||
		philos_ptr->time_to_sleep <= 6e4)
		print_error("Use a timestamp major than 60ms");
}

/**
 * init_forks - initializes data related to forks
 * @forks: pointer to data stucture of all forks
 * @philos: pointer to data stucture of all philos
 * @pnum: number of philosophers
 * 
 * Return: void.
*/
static void init_forks(t_fork *forks, t_philo *philos, int pnum)
{
	size_t	i;

	i = 0;
	
	while (i < (size_t)pnum)
	{
		forks->fork_id = i;
		if (pthread_mutex_init(&forks->fork, NULL) != 0)
			print_error("Error with Mutex!\n");
		philos->right_fork = forks;
		philos->forks = forks;
		i++;
		forks++;
		philos++;
	}
}
