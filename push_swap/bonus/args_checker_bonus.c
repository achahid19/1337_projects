/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:52:44 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 10:52:45 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool		args_checker(char *args);
static bool	args_first_check(char *str);
static bool	args_second_check(char *str);
void		args_duplicates_checker(char **args);

/**
 * args_checker -
*/
bool	args_checker(char *args)
{
	bool	status;

	status = true;
	if (false == args_first_check(args))
	{
		status = false;
		return (status);
	}
	if (false == args_second_check(args))
	{
		status = false;
		return (status);
	}
	return (status);
}

/**
 * args_first_check - checks the arguments passed to the program,
 * if one of them doesn't contain a digit, the execution
 * of the program is halted
 * @str: pointer to the argument to check
 * Return: false if there is no digit in str, otherwise true.
*/
static bool	args_first_check(char *str)
{
	bool	status;

	status = false;
	while (*str)
	{
		if (ft_isdigit(*str))
			status = true;
		if (ft_isdigit(*str) && (*(str + 1) != ' ' && *(str + 1) != '\0'
				&& !ft_isdigit(*(str + 1))))
		{
			status = false;
			break ;
		}
		str++;
	}
	return (status);
}

/**
 * args_second_check - takes the array of args passed on check 1 and process
 * a checks of the character next to the operators plus and minus, and verify
 * if there is any undesirable characters inserted in our array of arguments.
 * @str: pointer to the array of arguments to check
 * Return: true if str passed the checks, otherwise false.
*/
static bool	args_second_check(char *str)
{
	bool	status;

	status = true;
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (!ft_isdigit(*(str + 1)))
			{
				status = false;
				break ;
			}
		}
		if (!ft_isdigit(*str) && *str != '+' && *str != '-' && *str != ' ')
		{
			status = false;
			break ;
		}
		str++;
	}
	return (status);
}

/**
 * args_duplicates_checker - checks if the inputs
 * contains some duplicated numbers.
 * @args: pointer to the array of arguments (numbers to sort)
 * Return: void.
*/
void	args_duplicates_checker(char **args)
{
	size_t	i;
	size_t	j;
	long	num1;
	long	num2;

	i = 0;
	while (args[i] != NULL)
	{
		num1 = ft_atoi(args[i]);
		if (num1 > INT_MAX || num1 < INT_MIN)
			ft_print_error(args);
		j = i + 1;
		while (args[j] != NULL)
		{
			num2 = ft_atoi(args[j]);
			if (num2 > INT_MAX || num2 < INT_MIN)
				ft_print_error(args);
			if (num1 == num2)
				ft_print_error(args);
			j++;
		}
		i++;
	}
	return ;
}
