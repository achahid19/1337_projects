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

#include "../includes/philo.h"

void		init_data(t_philo *philos, t_fork *forks,
				t_program *program, char *args[]);
static void	init_program(t_program *program, t_philo *philos,
				t_fork *forks, char **args);
static void	init_forks(t_fork *forks, t_program *p, t_philo *philos, int pnum);
static void	init_philo(t_philo *philos, t_program *program, size_t i);
static void	assign_forks(t_philo *philos, int philos_number, size_t index);

/**
 * init_data - initialize the data related to each philosopher
 * @philos: pointer to data stucture of all philos
 * @forks: pointer to date stucture of all forks
 * @args: double pointer to program's arguments
 * 
 * Return: void.
*/
void	init_data(t_philo *philos, t_fork *forks,
			t_program *program, char *args[])
{
	size_t	i;
	int		philos_number;

	i = 0;
	philos_number = ft_atol(args[1]);
	init_program(program, philos, forks, args);
	init_forks(forks, program, philos, philos_number);
	while (i < (size_t)philos_number)
	{
		init_philo(philos, program, i);
		assign_forks(philos, philos_number, i);
		i++;
		philos++;
		forks++;
	}
}

/**
 * init_philo - init each philosopher related data
 * @philos: pointer to philos data list
 * @program: pointer to program struct
 * @i: iteration counter
 * 
 * Return: void.
*/
static void	init_philo(t_philo *philos, t_program *program, size_t i)
{
	philos->id = i + 1;
	philos->full = false;
	philos->number_of_meals_consumed = 0;
	philos->program = program;
	philos->simulation_start = 0;
	philos->dead_lock = &program->dead_lock;
	philos->write_lock = &program->write_lock;
	philos->meal_lock = &program->meal_lock;
	philos->full_lock = &program->full_lock;
	philos->simulation_start = gettime(milliseconds);
	philos->last_meal_counter = gettime(milliseconds);
}

/**
 * init_program - initialize program related data,
 * gathering mutexes and arguments needed for
 * simulation monitoring
 * @program: pointer to program struct
 * @philos: pointer to philos data list
 * @args: arguments
 * 
 * Return: void.
*/
static void	init_program(t_program *p, t_philo *philos,
				t_fork *forks, char **args)
{
	if (pthread_mutex_init(&p->dead_lock, NULL))
		mutex_destroy(p, "Error init program's mutex!\n", 0, false);
	if (pthread_mutex_init(&p->meal_lock, NULL))
		mutex_destroy(p, "Error init program's mutex!\n", 1, false);
	if (pthread_mutex_init(&p->write_lock, NULL))
		mutex_destroy(p, "Error init program's mutex!\n", 2, false);
	if (pthread_mutex_init(&p->full_lock, NULL))
		mutex_destroy(p, "Error init program's mutex!\n", 3, false);
	p->philos = philos;
	p->forks = forks;
	p->philo_num = ft_atol(args[1]);
	p->time_to_die = ft_atol(args[2]);
	p->time_to_eat = ft_atol(args[3]);
	p->time_to_sleep = ft_atol(args[4]);
	p->simulation_end = false;
	if (args[5])
		p->num_of_times_to_eat = ft_atol(args[5]);
	else
		p->num_of_times_to_eat = -1;
}

/**
 * init_forks - initializes data related to forks
 * @forks: pointer to data stucture of all forks
 * @philos: pointer to data stucture of all philos
 * @pnum: number of philosophers
 * 
 * Return: void.
*/
static void	init_forks(t_fork *forks, t_program *p, t_philo *philos, int pnum)
{
	size_t	i;

	i = 0;
	while (i < (size_t)pnum)
	{
		forks->fork_id = i;
		if (pthread_mutex_init(&forks->fork, NULL))
			mutex_destroy(p, "Error init forks's mutex!\n",
				4, i);
		philos->forks = forks;
		i++;
		forks++;
		philos++;
	}
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
			philos->second_fork = philos->forks + 1;
		else
			philos->second_fork = philos->forks - index;
	}
}
