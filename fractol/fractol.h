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

/* Window Resolution */
# define WIDTH 1000
# define HEIGHT 1000

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

/* Mandelbrot Set Data */
# define MAX_ITERATION 100// the more iteration, the more refined is the image
# define ESCAPE_VALUE 4 // Escaping the Mandelbrot Set
# define MAX_VAL_COL 15
# define X_MIN_PLAN -2
# define X_MAX_PLAN 2
# define Y_MIN_PLAN 2
# define Y_MAX_PLAN -2

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
	double		zoom;
	int			mouse_x;
	int			mouse_y;
	/* Julia Set */
	double		x_julia;
	double		y_julia;
	/* Color */
	int		color;
	int		max_val_col;
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
	int count;
	int count1;
	int sign;
	double result;
	double div;
	int div_count;
}	t_var;

/* fractol_utils */
int		ft_strncmp(const char *s1, const char *s2, int n);
size_t	ft_strlen(const char *str);

/* fractol utilities functions */
void	ft_fractol_init(t_mlx_data *mlx, char *window_name);
void	ft_fractol_render(t_mlx_data *mlx);
void	ft_fractol_hooks_loop(t_mlx_data *mlx);

/* static int		ft_key_hooks(int keysym, t_mlx_data *mlx);
static int		ft_close(t_mlx_data *mlx);
static void		ft_handle_pixel(int x, int y, t_mlx_data *mlx, int color); */
double	ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
//static void		ft_mandelbrot_julia_set(t_mlx_image *img_data, t_mlx_data *mlx, t_plan *complex, int x, int y);
int				ft_mouse_hooks(int button, int x, int y, t_mlx_data *mlx);
//static int		ft_close(t_mlx_data *mlx);
//static void		fractol_data_init(t_mlx_data *mlx);

void			ft_decimal_count(t_var *atoi, const char *str);
double			ft_atoi(const char *str);
void			ft_check_julia_input(const char *arg1, const char *arg2);
void			ft_julia_args_handler(const char *arg1, const char *arg2);

#endif /* FRACTOL_H */
