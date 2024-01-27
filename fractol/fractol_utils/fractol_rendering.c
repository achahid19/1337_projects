/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:58:18 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/26 14:58:19 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void		ft_handle_pixel(int x, int y, t_mlx_data *mlx, int color);
double			ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
static void		ft_mandelbrot_set(t_mlx_image *img_data, t_mlx_data *mlx, t_plan *complex, int x, int y);
static void		ft_init_set(t_vars *set, t_plan *complex, t_mlx_data *mlx);

/**
 * ft_fractol_render - iterates over all the pixles and checks if
 * the current pixel is part of Mandelbrot set, if its not
 * then the pixel got a certain color, once the image is rendered
 * mlx_put_image_to_window push the img to display's window
 * @mlx: pointer to mlx data
 * Return: void.
*/
void	ft_fractol_render(t_mlx_data *mlx)
{
	int		x;
	int		y;
	t_plan	complex_plan;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			complex_plan.real = (ft_pixel_scale((double)x, X_MIN_PLAN, X_MAX_PLAN, 0, WIDTH) * mlx->zoom) + mlx->shift_x;
			complex_plan.i = (ft_pixel_scale((double)y, Y_MIN_PLAN, Y_MAX_PLAN, 0, HEIGHT) * mlx->zoom) + mlx->shift_y;
			ft_mandelbrot_set(&mlx->img, mlx, &complex_plan, x, y); // I have passed the unscaled to handle the real pixel
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_win, mlx->img.img_ptr, 0, 0);
}

/**
 * ft_mandelbrot_set - iterates from a c position the following
 * equation Zn+1 = (Zn)^2 + c MAX_ITERATION times, if the point
 * is not respecting the Mandelbrot Set the pixel is handled with
 * ft_hanle_pixel function.
 * @img_data: pointer to data of the image data
 * @mlx: pointer to mlx data
 * @complex: pointer to the scaled coordinates of the pixel to check
 * @x: pixel coordinate in WIDTH axe
 * @y: pixel coordinate in HEIGHT axe
 * Return: void.
*/
static void	ft_mandelbrot_set(t_mlx_image *img_data, t_mlx_data *mlx, t_plan *complex, int x, int y)
{
	t_vars	set;
	
	ft_init_set(&set, complex, mlx);
	while (set.count < mlx->max_iteration)
	{
		set.tmp_real = (set.z.real * set.z.real) - (set.z.i * set.z.i);
		set.z.i = set.z.real * set.z.i * 2;
		set.z.real = set.tmp_real;
		set.z.real += set.c.real;
		set.z.i += set.c.i;
		if ((set.z.real * set.z.real) + (set.z.i * set.z.i) > ESCAPE_VALUE) // c = a^2 + b^2 // Pythagorean theorem
		{
			// BLACK IS THE ABSENCE OF COLORS, AND WHITE IS THE CONCOCTION OF ALL COLORS.(MIN, MAX)
			set.color = ft_pixel_scale(set.count, BLACK, WHITE, 0, MAX_VAL_COL);
			ft_handle_pixel(x, y, mlx, set.color);
			return ;
		}
		set.count++;
	}
	// WE ARA ON THE MANDELBROT SET!
	// maybe set a color for mandelbrot set.
	ft_handle_pixel(x, y, mlx, BLACK);
}
static void	ft_init_set(t_vars *set, t_plan *complex, t_mlx_data *mlx)
{
	if (0 == ft_strncmp(mlx->set_name, "Mandelbrot", 10))
	{
		set->z.real = 0;
		set->z.i = 0;
		set->c.real = complex->real;
		set->c.i = complex->i;
	}
	else if (0 == ft_strncmp(mlx->set_name, "Julia", 5))
	{
		set->z.real = complex->real;
		set->z.i = complex->i;
		set->c.real = mlx->x_julia;
		set->c.i = mlx->y_julia;
	}
}
/**
 * ft_pixel_scale - scale a number to fit some specific metrics
 * @unscaled_num: number to be scaled
 * @new_min: the new minimum value
 * @new_max: the new maximum value
 * @old_min: the old minimum value
 * @odl_max: the old maximum value
 * Return: scaled number.
*/
double	ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

/**
 * ft_handle_pixel - modify the offset of the pixel pointer
 * to apply the color on the corresponding pixel
 * @x: x-axis (coordinates address)
 * @y: y-axix (coodinates address)
 * @mlx: pointer to mlx data
 * @color: color value
 * Return: void
*/
static void	ft_handle_pixel(int x, int y, t_mlx_data *mlx, int color)
{
	int	offset;

	offset = (mlx->img.line_length * y) + (x * (mlx->img.bpp / 8));
	*((unsigned int*)(offset + mlx->img.pixel_addr)) = color;
}

void	ft_decimal_count(t_var *atoi, const char *str)
{
	atoi->div = 10;
	atoi->count1 = atoi->count + 1;
	atoi->div_count = 1;

	while (str[atoi->count1] >= '0' && str[atoi->count1] <= '9')
	{
		atoi->count1++;
		atoi->div_count++;
	}
	atoi->div_count--;
	atoi->count1 = 1;
	while (atoi->count1 < atoi->div_count)
	{
		atoi->div = atoi->div * 10;
		atoi->count1++;
	}
}
double  ft_atoi(const char *str)
{
	t_var  atoi;

	atoi.count = 0;
	atoi.sign = 1;
	atoi.result = 0;
	atoi.div = 1;
		while (str[atoi.count] == ' ')
		atoi.count++;
	if (str[atoi.count] == '-' || str[atoi.count] == '+')
	{
		if (str[atoi.count] == '-')
			atoi.sign = -atoi.sign;
		atoi.count++;
	}
	while ((str[atoi.count] >= '0' && str[atoi.count] <= '9') || str[atoi.count] == '.')
	{
		if (str[atoi.count] != '.')
			atoi.result = atoi.result * 10 + (str[atoi.count] - 48);
		else if (str[atoi.count] == '.')
			ft_decimal_count(&atoi, str);
		atoi.count++;
	}
	return ((atoi.result / atoi.div) * atoi.sign);
}
