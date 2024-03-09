/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:20:07 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 11:20:08 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void				main_stack_build(char **args, t_stack_ptr *a);
char				**read_instructions(t_stack_ptr a, char **args);
static char			*get_instruction(char *join, ssize_t *bytes_readed,
						t_stack_ptr a, char **args);
t_stack_ptr			actions_search_execute(t_stack_ptr a, t_stack_ptr *b,
						char **actions, char **args);
static t_bool		action_execute(char *action, t_stack_ptr *a,
						t_stack_ptr *b);

/**
 * main_stack_fill - build the stack which will contains all the metadata needed
 * @a: pointer to stack a (main stack)
 * @args: pointer to arguments which will be sorted on the stack
 * Return: void.
*/
void	main_stack_build(char **args, t_stack_ptr *a)
{
	t_stack_ptr	new;
	t_stack_ptr	tmp;

	(*a) = NULL;
	while (*args != NULL)
	{
		new = malloc(sizeof(t_stack_node));
		if (NULL == new)
			free_and_exit((*a), args, -1);
		new->num = ft_atoi(*args);
		new->next = NULL;
		if (NULL == (*a))
			(*a) = new;
		else
		{
			tmp = (*a);
			while (tmp->next != NULL)
				tmp = tmp->next;
			if (tmp->next == NULL)
				tmp->next = new;
		}
		args++;
	}
}

/**
 * read_instructions - reads from stdin the operations done by
 * push_swap program, then buffer them in a grid pointed
 * by **actions.
 * @a: pointer to main stack (a)
 * @args: double pointer to arguments (supposed to be only values)
 * Return: grid of push_swap actions.
*/
char	**read_instructions(t_stack_ptr a, char **args)
{
	char	**actions;
	char	*join;
	ssize_t	bytes_readed;

	actions = NULL;
	join = NULL;
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		join = get_instruction(join, &bytes_readed, a, args);
	}
	actions = ft_split(join, '\n');
	free(join);
	if (actions == NULL)
	{
		if (true == is_sorted(a))
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
		free_and_exit(a, args, -1);
	}
	return (actions);
}

/**
 * get_instruction -
*/
static char	*get_instruction(char *join, ssize_t *bytes_readed,
				t_stack_ptr a, char **args)
{
	char	*readed;

	readed = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (readed == NULL)
	{
		if (join != NULL)
			free(join);
		free_and_exit(a, args, -1);
	}
	*bytes_readed = read(0, readed, BUFFER_SIZE);
	if (*bytes_readed == -1)
	{
		if (join != NULL)
			free(join);
		free_and_exit(a, args, -1);
	}
	readed[*bytes_readed] = '\0';
	join = ft_strjoin(join, readed);
	free(readed);
	return (join);
}

/**
 * actions_apply - iterates over the push_swap actions
 * and call the execution function to match the operation
 * we have with the corresponding function.
 * @a: pointer to main stack (a)
 * @b: double pointer to temporary stack (b)
 * @actions: double pointer to push_swap actions
 * Return: pointer to main stack (a).
*/
t_stack_ptr	actions_search_execute(t_stack_ptr a, t_stack_ptr *b,
				char **actions, char **args)
{
	size_t	index;
	t_bool	status;

	index = 0;
	while (actions[index] != NULL)
	{
		status = action_execute(actions[index], &a, b);
		if (false == status)
		{
			if (b != NULL)
				free_stack((*b));
			free_all(args, a, actions);
			exit_error("Error\n", 2);
		}
		index++;
	}
	return (a);
}

/**
 * action_execute - call the corresponding function based on
 * the operation we got from push_swap program.
 * @action: pointer to the actiosn to execute.
 * @a: pointer to main the stack (a).
 * @b: double pointer to the temporary stack (b).
 * Return: pointer to the main stack (a).
*/
static t_bool	action_execute(char *action, t_stack_ptr *a, t_stack_ptr *b)
{
	t_bool	action_checker;

	action_checker = false;
	action_checker = stack_a_actions(action, a, b, action_checker);
	if (true == action_checker)
		return (true);
	action_checker = stack_b_actions(action, b, a, action_checker);
	if (true == action_checker)
		return (true);
	action_checker = both_stack_actions(action, a, b, action_checker);
	if (true == action_checker)
		return (true);
	return (action_checker);
}
