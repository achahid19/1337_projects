#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // for debugging
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

typedef enum e_bool
{
    false = 0,
    true = 1
}   t_bool;

/* utilities functions */
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);
t_bool  is_digit_space(char c, int space);

/* parsing */
t_bool	check_inputs(char *args[]);

/* errors */
void	print_error(const char *error);

# endif /* PHILO_H */
