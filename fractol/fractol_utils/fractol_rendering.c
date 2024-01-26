#include "../fractol.h"

static void		ft_handle_pixel(int x, int y, t_mlx_data *mlx, int color);
static double	ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
static void		ft_mandelbrot_set(t_mlx_image *img_data, t_mlx_data *mlx, t_plan *complex, int x, int y);

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
			complex_plan.real = ft_pixel_scale((double)x, -2, 2, 0, WIDTH);
			complex_plan.i = ft_pixel_scale((double)y, 2, -2, 0, HEIGHT);
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
	
	set.z.real = 0;
	set.z.i = 0;
	set.c.real = complex->real;
	set.c.i = complex->i;
	set.count = 0;
	while (set.count < MAX_ITERATION)
	{
		set.tmp_real = (set.z.real * set.z.real - set.z.i * set.z.i);
		set.z.i = set.z.real * set.z.i * 2;
		set.z.real = set.tmp_real;
		set.z.real += set.c.real;
		set.z.i += set.c.i;
		if ((set.z.real * set.z.real) + (set.z.i * set.z.i) > ESCAPE_VALUE)
		{
			set.color = ft_pixel_scale(set.count, BLACK, WHITE, 0, MAX_VAL_COL);
			ft_handle_pixel(x, y, mlx, set.color);
			return ;
		}
		set.count++;
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
static double	ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
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
