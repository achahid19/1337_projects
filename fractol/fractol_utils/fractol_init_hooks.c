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

#include "../fractol.h"

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
		exit(EXIT_FAILURE); // TODO perror for knowing the error
	mlx->mlx_win = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT, window_name);
	if (NULL == mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_connection, WIDTH, HEIGHT);
	if (NULL == mlx->img.img_ptr)
	{
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
	mlx->img.pixel_addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	if (NULL == mlx->img.pixel_addr)
	{
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		free(mlx->img.img_ptr);
		exit(EXIT_FAILURE);
	}
}

/**
 * ft_key_hooks - in the event of keypress, this function
 * checks for the keysym of the pressed key, and compare it
 * with the MACRO available on X11/keysym.h header file
 * @keysym: abstract representation of a keyboard key
 * @mlx: pointer to Mlx Data
 * Return: void
*/
static int	ft_key_hooks(int keysym, t_mlx_data *mlx) // TODO return value as int...
{
	if (XK_Escape == keysym) // for window cross
	{
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->img.img_ptr);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
}

/**
 * ft_fracto_hooks_loop - handle events and keeps the waiting
 * for them if no events is there
 * @mlx: ponter to mlx data
 * Return: void.
*/
void	ft_fractol_hooks_loop(t_mlx_data *mlx)
{
	mlx_key_hook(mlx->mlx_win, &ft_key_hooks, mlx);
	mlx_loop(mlx->mlx_connection);
}
