#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for debugging
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h> // gettimeofday.

typedef enum e_bool // define a set of named integer constant
{
    false = 0,
    true = 1
}   t_bool;

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
	/* Arguments */
	size_t		philo_num; // Also numbers of forks
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			num_of_times_to_eat; // Optional argument
	int			simulation_start;
	t_bool		simulation_end;
	/* Arguments */
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_fork		*forks; // array of forks
}	t_philo;

/* utilities functions */
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);

/* parsing */
t_bool	check_inputs(char *args[]);

/* errors */
void	print_error(const char *error);

# endif /* PHILO_H */
