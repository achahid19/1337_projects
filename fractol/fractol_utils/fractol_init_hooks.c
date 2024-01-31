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

static void	fractol_data_init(t_mlx_data *mlx);
static int	ft_close(t_mlx_data *mlx);
static int	ft_key_hooks(int keysym, t_mlx_data *mlx);
static int	ft_mouse_hooks(int button, int x, int y, t_mlx_data *mlx);

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
		mlx_destroy_image(mlx->mlx_connection, mlx->img.img_ptr);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractol_data_init(mlx);
}

static void	fractol_data_init(t_mlx_data *mlx)
{
	mlx->max_iteration = 50;
	mlx->shift_x = 0.0;
	mlx->shift_y = 0.0;
	mlx->zoom = 1.0;
	mlx->max_val_col = 15;
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
		ft_close(mlx);
	else if (XK_Left == keysym)
		mlx->shift_x += 0.5 * mlx->zoom; // shift propotionnely as the zoom increase or decrease
	else if (XK_Up == keysym)
		mlx->shift_y -= 0.5 * mlx->zoom;
	else if (XK_Down == keysym)
		mlx->shift_y += 0.5 * mlx->zoom;
	else if (XK_Right == keysym)
		mlx->shift_x -= 0.5 * mlx->zoom;
	// numbers are keysym for my ubuntu OS; X11/keysym for XK_plusminus ain't working!
	else if (XK_plus == keysym || 61 == keysym || 65451 == keysym) // + key; keysym do not work properly
	{
		mlx->max_iteration += 10;
		mlx->max_val_col += 1;
	}
	else if (XK_minus == keysym || 65453 == keysym) // - key; keysym do not work properly
	{
		mlx->max_iteration -= 10;
		mlx->max_val_col -= 1;
	}	
	// to referesh the image
	ft_fractol_render(mlx);
	return (0);
}

static int	ft_close(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_connection, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_connection);
	free(mlx->mlx_connection);
	exit(EXIT_SUCCESS);
}

static int	ft_mouse_hooks(int button, int x, int y, t_mlx_data *mlx)
{
	// zoom in == 5
	// zoom out == 4
	(void)x;
	(void)y;
	if (Button5 == button)
	{
		mlx->zoom *= 1.05;
	}
	if (Button4 == button)
	{
		mlx->zoom *= 0.95;
	}
    ft_fractol_render(mlx);
	return (0); // TODO in the others;
}
int	ft_julia_event(int x, int y, t_mlx_data *mlx)
{
	mlx->x_julia = ft_pixel_scale(x, X_MIN_PLAN, X_MAX_PLAN, 0, WIDTH);
	mlx->y_julia = ft_pixel_scale(y, Y_MIN_PLAN, Y_MAX_PLAN, 0, HEIGHT);
	ft_fractol_render(mlx);
	return (0);
}

/**
 * ft_fracto_hooks_loop - handle events and keeps the waiting
 * for them if no events is there
 * @mlx: ponter to mlx data
 * Return: void.
*/
void	ft_fractol_hooks_loop(t_mlx_data *mlx)
{
	/* keyboard handler */
	mlx_key_hook(mlx->mlx_win, &ft_key_hooks, mlx);
	/* Mouse handler */
	mlx_hook(mlx->mlx_win, ButtonPress, ButtonPressMask, &ft_mouse_hooks, mlx);
	/* cross x of window handler */
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask, &ft_close, mlx);
	/* Julia Set hook */
	if (0 == ft_strncmp(mlx->set_name, "Julia", 5))
		mlx_hook(mlx->mlx_win, MotionNotify, PointerMotionMask, &ft_julia_event, mlx);
	mlx_loop(mlx->mlx_connection);
}
