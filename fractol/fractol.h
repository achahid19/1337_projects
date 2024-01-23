/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:01:41 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/23 13:01:45 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // for debuggind
# include <stdlib.h> // malloc and free
# include <unistd.h> // write ...
# include "minilibx-linux/mlx.h"

# define INVALID_PARA "\033[1;31mParameters error:\n\033[0m\
		\033[1;33mList of available sets:\n\033[0m\
		- - - - - - - - - - - - - - - - - - - - - \n\
		> ./program_name Mandelbrot\n\
		> ./program_name Julia <real> <imaginary>\n\
		- - - - - - - - - - - - - - - - - - - - - \n"\

/* fractol_utils */
int		ft_strncmp(const char *s1, const char *s2, int n);
size_t	ft_strlen(const char *str);

#endif /* FRACTOL_H */
