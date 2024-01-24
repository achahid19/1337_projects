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
# include <X11/keysym.h>
# include <X11/Xlib.h>

# define INVALID_PARA "\033[1;31mParameters error:\n\033[0m\
		\033[1;33mList of available sets:\n\033[0m\
		- - - - - - - - - - - - - - - - - - - - - \n\
		> ./program_name Mandelbrot\n\
		> ./program_name Julia <real> <imaginary>\n\
		- - - - - - - - - - - - - - - - - - - - - \n"\

/* Mlx image data */
typedef struct s_mlx_image
{
	void	*img_ptr;
	char	*pixel_addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_image;

/* Mlx Data struct */
typedef struct s_mlx_data
{
	void		*mlx_connection;
	void		*mlx_win;
	t_mlx_image	img;
}	t_mlx_data;

/* Window Resolution */
# define WIDTH 1920
# define HEIGHT 1080

/* fractol_utils */
int		ft_strncmp(const char *s1, const char *s2, int n);
size_t	ft_strlen(const char *str);

/* fractol utilities functions */
void	ft_fractol_init(t_mlx_data *mlx, char *window_name);
int		ft_key_hooks(int keysym, t_mlx_data *mlx);
void	ft_fractol_hooks_loop(t_mlx_data *mlx);
int		cross_func(int button, t_mlx_data *mlx);

#endif /* FRACTOL_H */
