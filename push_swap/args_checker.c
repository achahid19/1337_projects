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

#include "push_swap.h"

static bool	args_first_check(char *str);
static bool	args_second_check(char *str);

/**
 * tab_to_fill - gather all checked arguments to a string then
 * create a 2d array of all the arguments. (passed first test).
 * @tab: pointer to the array of arguments
 * Return: tab.
*/
char	**args_checker(char **ptr_args)
{
	size_t	index;

	index = 0;
	while (ptr_args[index] != NULL)
	{
		if (false == args_first_check(ptr_args[index])) // if there no digit in the argument, then just exit.
		{
			printf("there no digit Error\n"); // TODO errors handling.
			exit(-1);
		}
		if (false == args_second_check(ptr_args[index])) // checks the arguments gathered, anything else is_digit(), '+', '-' and space.
		{
			printf("Error2"); // TODO errors handling.
			exit(-1);
		}
		index++;
	}
	return (ptr_args);
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
		/* if the character is a digit */
		if (ft_isdigit(*str))
			status = true;
		/* checks if after the digit is there any character else than space or null-terminating */
		if (ft_isdigit(*str) && (*(str + 1) != ' ' && *(str + 1) != '\0'))
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
	bool	condition;

	condition = true;
	while (*str)
	{
		/* if *str is plus or minus, have to check the character right after is a digit */
		if (*str == '+' || *str == '-')
		{
			if (!ft_isdigit(*(str + 1)))
			{
				condition = false;
				break ;
			}
		}
		/* if we found anthing else of digits, '+', '-' or ' ' */
		if (!ft_isdigit(*str) && *str != '+' && *str != '-' && *str != ' ')
		{
			condition = false;
			break ;
		}
		str++;
	}
	return (condition);
}
