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
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack_node
{
	int		num; // Current number on stack
	size_t	index;

	struct s_stack_node	*next;
} t_stack_node;

typedef t_stack_node *stack_ptr;

/* arguments checker */
char	**args_checker(char **ptr_args);
void	free_args(char **args);
void	ft_print_error(char *to_free);
void	ft_print_error2(char **args);

/* Build Main stack */
stack_ptr	main_stack_build(char **args);
void		free_main_stack(stack_ptr a);
size_t		get_stack_size(stack_ptr stack);
void		stack_indexing(stack_ptr stack_a, int size);

# endif /* PUSH_SWAP_H */
