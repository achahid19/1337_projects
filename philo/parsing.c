#include "philo.h"

t_bool		check_inputs(char *args[]);
static t_bool	check_arg(char *arg);
static t_bool	valid_num(char *args[], size_t index);
static t_bool	overflow_check(const char *arg);

/**
 * check_input - iterates over arguments, and call check_arg
 * to check them all.
 * @args: 2D array containing all arguments passed to the program
 * 
 * Return: t_boolean (true or false)
*/
t_bool	check_inputs(char *args[])
{
	// check av[1] to av[4] or av[5].
	// skip the program name
	size_t	index;

	index = 1;
	while (args[index])
	{
		// checks if the arg contains only digits.
		if (check_arg(args[index]) == false)
			return (false);
		// checks if the number is valid
		if (valid_num(args, index) == false)
			return (false);
		index++;
	}

	return (true);
}

/**
 * check_arg - checks each arguments if its contains
 * a none digit character
 * @arg: pointer to the argument
 * 
 * Return: t_boolean.
*/
static t_bool	check_arg(char *arg)
{
	t_bool	status;
	t_bool	digit;

	status = true;
	digit = false;
	while (*arg)
	{
		// check for digits
		if (*arg >= '0' && *arg <= '9')
			digit = true;
		// check if the character is not a digit or not a space
		else if (!(*arg >= '0' && *arg <= '9') && *arg != ' ')
		{
			status = false;
			break;
		}
		arg++;
	}
	if (digit == false)
		return (false);

	return (status);
}

/**
 * valid_num - checks for number validity;
 * All numbers should be bigger than 0, except for meals (av[5])
 * numbers of philos should be limited at 200.
 * @index: index of arg on args
 * 
 * Return: t_boolean.
*/
static t_bool	valid_num(char *args[], size_t index)
{
	int	num;

	if (overflow_check(args[index]) == false)
		return (false);
	num = ft_atol(args[index]);
	if (index >= 1 && index <= 4)
	{
		if (index == 1)
		{
			if (num > 200)
				return (false);
		}
		if (num == 0)
			return (false);
	}

	return (true);
}

/**
 * overflow_check - protects from having a overflow case
 * @arg: pointer to the number to check
 * 
 * Return: t_boolean (true of false).
*/
static t_bool	overflow_check(const char *arg)
{
	size_t	length;
	long	num;

	length = ft_strlen(arg);
	num = atol(arg);
	if (length > 10 || num > INT_MAX)
		return (false);

	return (true);
}
