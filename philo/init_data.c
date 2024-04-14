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


void		init_data(t_philo *philos, t_fork *forks, t_program *program, char *args[]);
static void	init_forks(t_fork *forks, t_philo *philos, int pnum);
static void	assign_forks(t_philo *philos, int philos_number, size_t index);

/**
 * init_data - initialize the data related to each philosopher
 * @philos: pointer to data stucture of all philos
 * @forks: pointer to date stucture of all forks
 * @args: double pointer to program's arguments
 * 
 * Return: void.
*/
void	init_data(t_philo *philos, t_fork *forks, t_program *program, char *args[])
{
	size_t	i;
	int 	philos_number;

	i = 0;
	philos_number = ft_atol(args[1]);
	// program
	if (pthread_mutex_init(&program->dead_lock, NULL))
		print_error("Error initializing program's mutex!\n");
	if (pthread_mutex_init(&program->meal_lock, NULL))
		print_error("Error initializing program's mutex!\n");
	if (pthread_mutex_init(&program->write_lock, NULL))
		print_error("Error initializing program's mutex!\n");
	program->threads_ready = false;
	program->philos = philos;
	program->philo_num = philos_number;
	program->time_to_die = ft_atol(args[2]);
	program->time_to_eat = ft_atol(args[3]);
	program->time_to_sleep = ft_atol(args[4]);
	program->simulation_end = false;	
	program->threads_ready = false;
	if (args[5])
		program->num_of_times_to_eat = ft_atol(args[5]);
	else
		program->num_of_times_to_eat = -1;
	if (program->time_to_die <= 60 ||
		program->time_to_eat <= 60 ||
		program->time_to_sleep <= 60)
		print_error("Use a timestamp major than 60ms");
	//
	init_forks(forks, philos, philos_number);
	while (i < (size_t)philos_number)
	{
		philos->id = i + 1;
		philos->full = false;
		philos->last_meal_counter = 0;		
		philos->number_of_meals_consumed = 0;
		philos->program = program;
		philos->death = 0;
		philos->simulation_start = 0;
		philos->dead_lock = &program->dead_lock;
		philos->write_lock = &program->write_lock;
		philos->meal_lock = &program->meal_lock;
		assign_forks(philos, philos_number, i);
		printf("in call: %ld, for philo id: %d, first fork is %d and second fork \
		is: %d\n", i, philos->id, philos->first_fork->fork_id, philos->second_fork->fork_id);
		i++;
		philos++;
		forks++;
	}
	philos = NULL;
	forks = NULL;
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
		philos->forks = forks; // each philo points to his right fork.
		i++;
		forks++;
		philos++;
	}
	forks = NULL;
	philos = NULL;
}

/**
 * assign_forks - syncrhonize assignement of forks over the philosophers
 * if odd number the first_fork will be fork on his left (next philo's fork),
 * and the second its the second on his right.
 * if even the first_fork is the one on his right,
 * and second_fork will be on his left.
 * @philos: pointer to data stucture of all philos
 * @philos_number: number of philos passed to the program
 * @index: index of each iteration.
 * 
 * Return: void.
*/
static void	assign_forks(t_philo *philos, int philos_number, size_t index)
{
	if (philos->id % 2 != 0)
	{
		// data stucture is circulaire, so for the last philo the fork on
			// his left is the fork of the assigned to the first philo 
			// at first place... (forks needs to be syncronized over philos!!)
		if (index < (size_t)philos_number - 1)
			philos->first_fork = philos->forks + 1;
		else
			philos->first_fork = philos->forks - index;
		philos->second_fork = philos->forks;
	}
	else if (philos->id % 2 == 0)
	{
		philos->first_fork = philos->forks;
		if (index < (size_t)philos_number - 1)
			philos->second_fork = philos->forks +1;
		else
			philos->second_fork = philos->forks - index;
	}
}
