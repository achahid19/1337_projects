/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:46 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:56:47 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool			check_inputs(char *args[]);
static t_bool	check_arg(char *arg);
static t_bool	is_digit_space(char c, int space);
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
	size_t	index;

	index = 1;
	while (args[index])
	{
		if (check_arg(args[index]) == false
			|| valid_num(args, index) == false)
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
	t_bool	digit;

	digit = false;
	while (*arg)
	{
		if (is_digit_space(*arg, 0) == true)
			digit = true;
		else if (is_digit_space(*arg, 1) == false)
			return (false);
		else if (is_digit_space(*arg, 2) == true && digit == true)
		{
			while (*arg)
			{
				if (is_digit_space(*arg, 2) == false)
					return (false);
				arg++;
			}
			break ;
		}
		arg++;
	}
	if (digit == false)
		return (false);
	return (true);
}

/**
 * is_digit_space - Checks the character passed
 * is it a digit or space
 * @c: character to check
 * @space: if space is 0, it means that space is off, 
 * only check for digits, or if its 1 the checking for
 * space is activeted.
 * 
 * Return: boolean.
*/
static t_bool	is_digit_space(char c, int space)
{
	if (space == false)
		return (c >= '0' && c <= '9');
	else if (space == true)
		return ((c >= '0' && c <= '9') || (c >= 9 && c <= 13) || c == ' ');
	return ((c >= 9 && c <= 13) || c == ' ');
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

	if (overflow_check(args[index]) == true)
		return (false);
	num = ft_atol(args[index]);
	if (index >= 1 && index <= 4)
	{
		if (index == 1)
		{
			if (num > PHILO_LIMIT)
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
	long	num;

	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) > 10)
		return (true);
	num = ft_atol(arg);
	return (num > INT_MAX);
}
