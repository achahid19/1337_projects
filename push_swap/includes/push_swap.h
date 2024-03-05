/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:12:47 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/18 13:12:49 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // for debugging
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

typedef enum e_bool // define a set of named integer constants.
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_stack_node
{
	int					num; // Current number on stack
	size_t				index; // indexing each element on stack a
	int					pos; // position of each element on the stack
	int					target_pos;
	int					ca; // cost of a
	int					cb; // cost of b
	struct s_stack_node	*next; // pointer to the next element
}	t_stack_node;

typedef t_stack_node	*t_stack_ptr;

/* arguments checker */
char		**args_checker(char **ptr_args);
void		free_args(char **args);
void		ft_print_error(char *to_free);
void		ft_print_error2(char **args);

/* Build Main stack */
t_stack_ptr	main_stack_build(t_stack_ptr a, char **args);
void		free_main_stack(t_stack_ptr a);
size_t		get_stack_size(t_stack_ptr stack);
void		stack_indexing(t_stack_ptr a, int size);
void		free_and_exit(t_stack_ptr stack, char **args);

/* Action's prototypes */
void		swap(t_stack_ptr a, char *str);
t_stack_ptr	rotate(t_stack_ptr stack, char *str);
t_stack_ptr	rev_rotate(t_stack_ptr stack, char *str);
t_stack_ptr	push(t_stack_ptr a, t_stack_ptr *b, char *str);
t_stack_ptr	rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);
t_stack_ptr	rev_rotate_both_stack(t_stack_ptr a, t_stack_ptr *b);

/* push_swap utils */
t_stack_ptr	find_last_node(t_stack_ptr a);
t_bool		is_sorted(t_stack_ptr a);
size_t		find_hindex(t_stack_ptr a);
t_stack_ptr	find_blast_node(t_stack_ptr a);

/* move utils */
t_stack_ptr	lowest_cost_move(t_stack_ptr a, t_stack_ptr *b);
t_stack_ptr	stack_shifting(t_stack_ptr a);
int			ft_abs(int num);

/* bigSort utils */
t_stack_ptr	saveof3(t_stack_ptr a, t_stack_ptr *b, size_t size_a);
void		get_pos(t_stack_ptr stack);
void		target_pos(t_stack_ptr a, t_stack_ptr *b);
void		cost_get(t_stack_ptr a, t_stack_ptr *b);

#endif /* PUSH_SWAP_H */
