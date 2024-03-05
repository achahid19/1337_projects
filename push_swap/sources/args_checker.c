/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:05 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/20 10:28:07 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		**args_checker(char **ptr_argv);
static t_bool	args_first_check(char *str);
static t_bool	args_second_check(char *str);
static void	args_duplicates_checker(char **args);

/**
 * tab_to_fill - gather all checked arguments to a string then
 * create a 2d array of all the arguments. (passed first test).
 * @ptr_argv: pointer to the array of arguments
 * Return: tab.
*/
char	**args_checker(char **ptr_argv)
{
	size_t	index;
	char	*join;

	index = 0;
	join = NULL;
	while (ptr_argv[index] != NULL)
	{
		if (false == args_first_check(ptr_argv[index]))
			ft_print_error(join);
		if (false == args_second_check(ptr_argv[index]))
			ft_print_error(join);
		join = ft_strjoin(join, " ");
		join = ft_strjoin(join, ptr_argv[index]);
		index++;
	}
	ptr_argv = ft_split(join, ' ');
	free(join);
	args_duplicates_checker(ptr_argv);
	return (ptr_argv);
}

/**
 * args_first_check - checks the arguments passed to the program,
 * if one of them doesn't contain a digit, the execution
 * of the program is halted
 * @str: pointer to the argument to check
 * Return: false if there is no digit in str, otherwise true.
*/
static t_bool	args_first_check(char *str)
{
	t_bool	status;

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
 * a checks to the character next to the operators plus and minus, and verify
 * if there is any undesirable characters inserted in our array of arguments.
 * @str: pointer to the array of arguments to check
 * Return: true if str passed the checks, otherwise false.
*/
static t_bool	args_second_check(char *str)
{
	t_bool	status;

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
static void	args_duplicates_checker(char **args)
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
			ft_print_error2(args);
		j = i + 1;
		while (args[j] != NULL)
		{
			num2 = ft_atoi(args[j]);
			if (num2 > INT_MAX || num2 < INT_MIN)
				ft_print_error2(args);
			if (num1 == num2)
				ft_print_error2(args);
			j++;
		}
		i++;
	}
	return ;
}
