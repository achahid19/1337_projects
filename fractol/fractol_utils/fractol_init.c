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

#include "../inc/fractol.h"

static void	fractol_data_init(t_mlx_data *mlx);
int			ft_close(t_mlx_data *mlx);

/**
 * ft_fractol_init - Establish the cnx with X Server, Create
 * the window the initialize the img in the window
 * @mlx: pointer to mlx Data
 * @window_name: name of the current window
 * Return: void.
*/
void	ft_fractol_init(t_mlx_data *mlx, char *window_name)
{
	mlx->mlx_connection = mlx_init();
	if (NULL == mlx->mlx_connection)
		ft_perror(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx_connection, W,
			H, window_name);
	if (NULL == mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_connection);
		ft_perror(mlx);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_connection, W, H);
	if (NULL == mlx->img.img_ptr)
	{
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		ft_perror(mlx);
	}
	mlx->img.pixel_addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp,
			&mlx->img.line_length,
			&mlx->img.endian);
	if (NULL == mlx->img.pixel_addr)
		ft_close(mlx);
	fractol_data_init(mlx);
}

static void	fractol_data_init(t_mlx_data *mlx)
{
	mlx->shift_x = 0.0;
	mlx->shift_y = 0.0;
	mlx->max_val_col = 15;
	mlx->max_iteration = 81;
	mlx->x_min = -2.0;
	mlx->x_max = 2.0;
	mlx->y_min = -2.0;
	mlx->y_max = 2.0;
	mlx->zoom_shift = 0.50;
	mlx->tricorn = 1;
}

int	ft_close(t_mlx_data *mlx)
{
	if (NULL == mlx->img.pixel_addr)
	{
		mlx_destroy_image(mlx->mlx_connection, mlx->img.img_ptr);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		ft_perror(mlx);
	}
	else if (NULL != mlx->img.pixel_addr)
	{
		mlx_destroy_image(mlx->mlx_connection, mlx->img.img_ptr);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
