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
# include <stdbool.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack_node
{
	int		num; // Current number on stack
	size_t	index; // indexing each element on stack a
	int 	pos; // position of each element on the stack
	int		target_pos; // targeting a B element to a position on stack a.
	int		ca; // cost of a
	int		cb; // cost of b
	struct s_stack_node	*next; // pointer to the next element
} t_stack_node;

typedef t_stack_node *stack_ptr;

/* arguments checker */
char		**args_checker(char **ptr_args);
void		free_args(char **args);
void		ft_print_error(char *to_free);
void		ft_print_error2(char **args);

/* Build Main stack */
stack_ptr	main_stack_build(char **args);
void		free_main_stack(stack_ptr a);
size_t		get_stack_size(stack_ptr stack);
void		stack_indexing(stack_ptr stack_a, int size);
void		free_and_exit(stack_ptr stack, char **args);

/* Action's prototypes */
void		swap(stack_ptr a, char *str);
stack_ptr	rotate(stack_ptr stack, char *str);
stack_ptr	rev_rotate(stack_ptr stack, char *str);
stack_ptr	push(stack_ptr a, stack_ptr *b, char *str);
stack_ptr	rotate_both_stack(stack_ptr a, stack_ptr *b);
stack_ptr	rev_rotate_both_stack(stack_ptr a, stack_ptr *b);

/* push_swap utils */
stack_ptr	find_last_node(stack_ptr a);
bool		is_sorted(stack_ptr a);
size_t		find_hindex(stack_ptr a);
stack_ptr	find_blast_node(stack_ptr a);

/* move utils */
stack_ptr	lowest_cost_move(stack_ptr a, stack_ptr *b);
stack_ptr	stack_shifting(stack_ptr a);
int			ft_abs(int num);

/* bigSort utils */
stack_ptr	saveOf3(stack_ptr a, stack_ptr *b, size_t size_a);
void		get_pos(stack_ptr stack);
void		target_pos(stack_ptr a, stack_ptr *b);
void		cost_get(stack_ptr a, stack_ptr *b);

# endif /* PUSH_SWAP_H */
