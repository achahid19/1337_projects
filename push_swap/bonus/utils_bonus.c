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
static void			node_init(t_stack_ptr *new, char **args);
char				**read_instructions(t_stack_ptr a, char **args);
static t_stack_ptr	action_execute(char *action, t_stack_ptr a, t_stack_ptr *b);
t_stack_ptr			actions_search_execute(t_stack_ptr a, t_stack_ptr *b,
						char **actions);

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
		node_init(&new, args);
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
 * node_init - initialize the variables of the new node
 * created to be added to the stack
 * @new: pointer to the new created element
 * @args: double pointer to arguments
 * Return: void.
*/
static void	node_init(t_stack_ptr *new, char **args)
{
	(*new)->num = ft_atoi(*args);
	(*new)->next = NULL;
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
	join = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (join == NULL)
		free_and_exit(a, args, -1);
	bytes_readed = read(0, join, BUFFER_SIZE);
	join[bytes_readed] = '\0';
	if (bytes_readed == -1)
		free_and_exit(a, args, -1);
	if (bytes_readed > 0)
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
 * action_execute - call the corresponding function based on
 * the operation we got from push_swap program.
 * @action: pointer to the actiosn to execute.
 * @a: pointer to main the stack (a).
 * @b: double pointer to the temporary stack (b).
 * Return: pointer to the main stack (a).
*/
static t_stack_ptr	action_execute(char *action, t_stack_ptr a, t_stack_ptr *b)
{
	if (!ft_strncmp(action, "sa", 2))
		swap(a, "sa");
	else if (!ft_strncmp(action, "ra", 2))
		a = rotate(a, "ra");
	else if (!ft_strncmp(action, "rb", 2))
		rotate((*b), "rb");
	else if (!ft_strncmp(action, "rra", 3))
		a = rev_rotate(a, "rra");
	else if (!ft_strncmp(action, "rrb", 3))
		rev_rotate((*b), "rrb");
	else if (!ft_strncmp(action, "pa", 2))
		a = push(a, b, "pa");
	else if (!ft_strncmp(action, "pb", 2))
		a = push(a, b, "pb");
	else if (!ft_strncmp(action, "rr", 2))
		a = rotate_both_stack(a, b);
	else if (!ft_strncmp(action, "rrr", 3))
		a = rev_rotate_both_stack(a, b);
	else
		exit_error("Error\n", 2);
	return (a);
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
				char **actions)
{
	size_t	index;

	index = 0;
	while (actions[index] != NULL)
	{
		a = action_execute(actions[index], a, b);
		index++;
	}
	return (a);
}
