/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:27 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:56:29 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for debugging
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h> // gettimeofday.

# define PHILO_LIMIT 200 // limits number of philos

typedef enum e_bool // define a set of named integer constant
{
    false = 0,
    true = 1
}   t_bool;

typedef enum e_time
{
	microseconds = 0,
	milliseconds = 1,
	seconds = 2
}	t_time;

typedef struct s_fork // Array of forks.
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread; // each philo is a thread
	int			id;
	t_bool		full; // number of max meals
	int			last_meal_counter; // time passed from last meal
	int			number_of_meals_consumed;
	/* forks */
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_fork		*forks; // array to forks
}	t_philo;

typedef	struct s_program
{
	t_bool			threads_ready;
	t_philo 		*philos;
	pthread_mutex_t	program_mutex;
	/**/
	size_t		philo_num; // Also numbers of forks
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			num_of_times_to_eat; // Optional argument
	t_bool		simulation_end; // philo's death or full meals.
	long		simulation_start;
	/**/
} t_program;

/* utilities functions */
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);

/* parsing */
t_bool	check_inputs(char *args[]);

/* errors */
void	print_error(const char *error);

/* philos */
void	init_data(t_philo *philos, t_fork *forks, t_program *program, char *args[]);
void	philos_call(t_philo *philos, t_program *program);
void	philos_syncro(t_philo *philos, t_program *p);

# endif /* PHILO_H */
