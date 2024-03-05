/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bunus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:35:50 by achahid-          #+#    #+#             */
/*   Updated: 2024/03/03 10:35:51 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 20000 // instructions readed

#ifndef BOOL_H
# define BOOL_H

typedef enum // define a set of named integer constants.
{
	false = 0,
	true = 1
}	t_bool;

#endif /* BOOL_H */

typedef struct s_stack_node
{
	int					num;
	struct s_stack_node	*next;
}	t_stack_node;


typedef t_stack_node	*t_stack_ptr;

/* arguments checker */
t_bool		args_checker(char *args);
void		args_duplicates_checker(char **args);
void		free_main_stack(t_stack_ptr a);

/* freeing and erros */
void		exit_error(char *error, int fd);
void		ft_print_error(char **args);
void		free_args(char **args);
void		free_and_exit(t_stack_ptr stack, char **args, int status);

/* Build main stack */
void		main_stack_build(char **args, t_stack_ptr *a);

/* Checker */
char		**read_instructions(t_stack_ptr a, char **args);
t_stack_ptr	actions_search_execute(t_stack_ptr a, t_stack_ptr *b,
				char **actions);

/* Actions */
void		swap(t_stack_ptr a, char *str);
t_stack_ptr	rotate(t_stack_ptr stack, char *str);
t_stack_ptr	rev_rotate(t_stack_ptr stack, char *str);
t_stack_ptr	push(t_stack_ptr a, t_stack_ptr *b, char *str);
t_stack_ptr	rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);
t_stack_ptr	rev_rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);

/* Utils2 */
size_t		get_stack_size(t_stack_ptr stack);
t_stack_ptr	find_last_node(t_stack_ptr a);
t_stack_ptr	find_blast_node(t_stack_ptr a);
t_bool		is_sorted(t_stack_ptr a);
void		free_all(char **args, t_stack_ptr a, char **actions);

#endif /* PUSH_SWAP_BONUS_H */
