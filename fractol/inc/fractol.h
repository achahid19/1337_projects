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
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>

# define INVALID_PARA "\033[1;31mParameters error:\n\033[0m\
		\033[1;33mList of available sets:\n\033[0m\
		- - - - - - - - - - - - - - - - - - - - - \n\
		> ./fractol Mandelbrot\n\
		> ./fractol Julia <real> <imaginary>\n\
		> ./fractol Tricorn\n\
		- - - - - - - - - - - - - - - - - - - - - \n"\

/* Window Resolution */
# define W 1000
# define H 1000

/* Standard colors */
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF

/* Psychedelic colors */
# define PSYCH_RED     0xFF00CC
# define PSYCH_GREEN   0x00FFCC
# define PSYCH_BLUE    0x00CCFF
# define PSYCH_YELLOW  0xFFCC00
# define PSYCH_CYAN    0xCCFF00
# define PSYCH_MAGENTA 0xCC00FF

/* Sets Data */
# define ESCAPE_VALUE 4 // Escaping the Mandelbrot Set
# define ZOOM_MULT 0.10 // Zoom Speed

/* Keysyms */
# define XK_L_PLUS 61
# define XK_R_MINUS 65453
# define XK_R_PLUS 65451

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
	char		*set_name;
	/* hooks variables */
	int			max_iteration;
	double		shift_x;
	double		shift_y;
	double		zoom_shift;
	/* Julia Set */
	double		x_julia;
	double		y_julia;
	/* Color */
	int			color;
	int			max_val_col;
	/* complex plan scaled metrics */
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	/* for tricorn set */
	int			tricorn;
}	t_mlx_data;

/* complex plan struct for coordinates */
typedef struct s_plan
{
	double	real;
	double	i;
}	t_plan;

/* Mandelbrot variables */
typedef struct s_vars
{
	t_plan	z;
	t_plan	c;
	size_t	count;
	double	tmp_real;

}	t_vars;

/* ft_atoi double struct */
typedef struct s_var
{
	int		count;
	int		count1;
	int		sign;
	double	result;
	double	div;
	int		div_count;
}	t_var;

/* fractol_utils */
int		ft_strncmp(const char *s1, const char *s2, int n);
size_t	ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);

/* fractol utilities functions */
void	ft_fractol_init(t_mlx_data *mlx, char *window_name);
void	ft_fractol_render(t_mlx_data *mlx);
void	ft_fractol_hooks_loop(t_mlx_data *mlx);
int		ft_close(t_mlx_data *mlx);

/* Math lib */
double	ft_scale(double unscaled_num, double n_min, double n_max, double o_max);
double	ft_atoi(const char *str);

/* Julia Set parsing */
void	ft_check_julia_input(const char *arg1, const char *arg2);

/* for errors */
void	ft_print_error(char *error);
void	ft_perror(t_mlx_data *mlx);

#endif /* FRACTOL_H */
