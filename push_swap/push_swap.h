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
	size_t	index;
	int 	pos;
	int		target_pos;
	int		ca;
	int		cb;
	struct s_stack_node	*next;
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

/* Action's prototypes */
void		swap(stack_ptr a, char *str);
stack_ptr	ra(stack_ptr a);
stack_ptr	rra(stack_ptr a);
stack_ptr	push(stack_ptr a, stack_ptr *b, char *str);

/* push_swap utils */
stack_ptr	find_last_node(stack_ptr a);
bool		is_sorted(stack_ptr a);
size_t		find_hindex(stack_ptr a);
stack_ptr	find_blast_node(stack_ptr a);

/* bigSort utils */
stack_ptr	saveOf3(stack_ptr a, stack_ptr *b, size_t size_a);
void		get_pos(stack_ptr stack);
void		target_pos(stack_ptr a, stack_ptr *b, size_t size_a);

# endif /* PUSH_SWAP_H */
