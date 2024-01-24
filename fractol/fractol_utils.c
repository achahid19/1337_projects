/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:02:02 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/23 13:02:05 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * ft_strncmp - compares n bytes between s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compares
 * Return: 0 if s1 == s2, > 0 if s1 > s2, othwise < 0 if s1 < s2
*/
int ft_strncmp(const char *s1, const char *s2, int n)
{
    if (!s1 || !s2 || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        *s1++;
        *s2++;
        --n;
    }
    return (*s1 - *s2);
}

/**
 * ft_strlen - counts the length of str
 * @str: string
 * Return: length of str
*/
size_t  ft_strlen(const char *str)
{
    /* base case to stop the recursion */
    if (NULL == str || '\0' == *str)
        return (0);
    /* recursive case */
    return (ft_strlen(str + 1) + 1);
}

/**
 * ft_fractol_init
*/

void	ft_fractol_init(t_mlx_data *mlx, char *window_name)
{
	// Establish the connection to X server, and set the display on this display
	mlx->mlx_connection = mlx_init();
	if (NULL == mlx->mlx_connection)
		exit(EXIT_FAILURE); // TODO perror for knowing the error
	// Create the window
	mlx->mlx_win = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT, window_name);
	if (NULL == mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
	// initialize the image in the window
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_connection, WIDTH, HEIGHT);
	if (NULL == mlx->img.img_ptr)
	{
		mlx_destroy_display(mlx->mlx_connection);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
	// Now that we have our image where to push our pixels, is up to us
	// to handle the management of those pixels push, mlx_pixel_put is very
	// slow, it push instantly without waiting for the frame to be
	// entirely rendered. for that reason we will buffer all our pixels to a
	// image, which we will then push to the window.
	mlx->img.pixel_addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	if (NULL == mlx->img.pixel_addr)
	{
		mlx_destroy_display(mlx->mlx_connection);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
}

int	ft_key_hooks(int keysym, t_mlx_data *mlx)
{
	if (XK_Escape == keysym) // for window cross
	{
		mlx_destroy_display(mlx->mlx_connection);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
}

/* int	cross_func(int button, t_mlx_data *mlx)
{
	printf("button: %d\n", button);
	if (button == 1) // Clicking with the right button
	{
			mlx_destroy_display(mlx->mlx_connection);
			mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
			free(mlx->mlx_connection);
			exit(EXIT_FAILURE);
	}
} */

void	color_pixel_mandelbrot_set(t_mlx_image *img_data, t_mlx_data *mlx_data)
{

}

// Zn+1 = z^2 + c // (x + yi)(x + yi) + c
// x^2 + 2xyi + - y^2 + c==> ((x^2 - y^2) + 2xyi) + c==> z
int	ft_mandelbrot_set(t_mlx_image *img_data, t_mlx_data *mlx, t_plan *complex)
{
	t_plan	z;
	t_plan	c;
	size_t  count;
	double	tmp_real;
	
	z.real = 0;
	z.i = 0;
	c.real = complex->real;
	c.i = complex->i;
	count = 0;
	while (count < 20)
	{
		tmp_real = (z.real * z.real - z.i * z.i);
		z.i = z.real * z.i * 2;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		/* if it goes out the limits while iterating, so its not Mandelbrot set */
		if (!(z.real > -2 && z.real < 2) || !(z.i > -2 && z.i < 2))
			return (-1);
		count++;
	}
	return (1);
}
void	ft_fractol_hooks_loop(t_mlx_data *mlx, char *set_name)
{
	mlx_key_hook(mlx->mlx_win, &ft_key_hooks, mlx);
	/* mlx_mouse_hook(mlx->mlx_win, &cross_func, mlx); */ // TODO the cross button.
	/* if (0 == ft_strncmp(set_name, "Mandelbrot", 10))
		ft_mandelbrot_set(&mlx->img, mlx); */
	mlx_loop(mlx->mlx_connection);
}

double	ft_pixel_scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max) // To ADD .H
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

/**
 *  SCALING - from for instance [0..800] to [-2..2]
 *
 * 	 0,0 -------- 799,0      -2,0 -------- +2,0
 *	 	|         |     		 |         |
 *  	|         |    	==>		 |         |
 *	 	|         |				 |         |
 *	 	|         |				 |         |
 *0,799	 --------- 799,799   0,-2 --------- 0,2
*/
/* void	ft_pixel_set(int x, int y, t_mlx_data *mlx) // TO ADD .H
{
	// Now I have the scale of mandelbrot set, complex plan coordinates
	printf("(%.02f, %.02f)\n", ft_pixel_scale((double)x, -2, 2, 0, WIDTH), ft_pixel_scale((double)y, -2, 2, 0, HEIGHT));
} */

void	ft_fractol_render(t_mlx_data *mlx)
{
	int		x;
	int		y;
	t_plan	complex_plan;

	y = 0;
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			/* ft_pixel_set(x , y, mlx); */ // the problem is we have to scale to fit the coordinates of the mandelbrot set
			complex_plan.real = ft_pixel_scale((double)x, -2, 2, 0, WIDTH);
			complex_plan.i = ft_pixel_scale((double)y, -2, 2, 0, HEIGHT);
			/* printf("scaled from: (%d, %d) to (%.02f, %.02f)\n", x, y, complex_plan.real, complex_plan.i); */
			/**
			 * Now that I scaled my plan, I have to check if
			 * each coordinates (real, imaginary) is member
			 * of the Mandelbrot Set, if it is we color the
			 * corresponding pixel w
			int set = ft_mandelbrot_set(&mlx->img, mlx, &complex_plan);
			printf("%d\n", set);ith a certain color.
			*/
			int set = ft_mandelbrot_set(&mlx->img, mlx, &complex_plan);
			if (-1 == set)
			{
				printf("set (%.02f, %.02f) is not a Mandelbrot Set!\n", complex_plan.real, complex_plan.i);
			}
			if (1 == set)
			{
				printf("set (%.02f, %.02f) is a Mandelbrot Set!\n", complex_plan.real, complex_plan.i);
				/* here I have to handle the pixels that are members of the Mandelbrot Set */
			}
		}
		y++;
	}
}
