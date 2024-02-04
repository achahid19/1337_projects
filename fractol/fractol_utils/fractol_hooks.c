/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:28:17 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/01 11:28:18 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			ft_julia_event(int x, int y, t_mlx_data *mlx);
static int	ft_mouse_hooks(int button, int x, int y, t_mlx_data *mlx);
static int	ft_key_hooks(int keysym, t_mlx_data *mlx);

/**
 * ft_fracto_hooks_loop - handle events and keeps the waiting
 * for them if no events is there
 * @mlx: ponter to mlx data
 * Return: void.
*/
void	ft_fractol_hooks_loop(t_mlx_data *mlx)
{
	mlx_key_hook(mlx->mlx_win, &ft_key_hooks, mlx);
	mlx_hook(mlx->mlx_win, ButtonPress, ButtonPressMask, &ft_mouse_hooks, mlx);
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask, &ft_close, mlx);
	if (0 == ft_strncmp(mlx->set_name, "Julia", 5))
	{
		mlx_hook(mlx->mlx_win, MotionNotify, PointerMotionMask,
			&ft_julia_event, mlx);
	}
	mlx_loop(mlx->mlx_connection);
}

int	ft_julia_event(int x, int y, t_mlx_data *mlx)
{
	mlx->x_julia = ft_scale(x, mlx->x_min, mlx->x_max, W);
	mlx->y_julia = ft_scale(y, mlx->y_min, mlx->y_max, H);
	ft_fractol_render(mlx);
	return (0);
}

static int	ft_mouse_hooks(int button, int x, int y, t_mlx_data *mlx)
{
	double	ratio_x;
	double	ratio_y;

	ratio_x = (mlx->x_max - mlx->x_min) / W;
	ratio_y = (mlx->y_max - mlx->y_min) / H;
	if (Button4 == button)
	{
		mlx->zoom_shift *= 0.90;
		mlx->x_min += (ratio_x * x) * ZOOM_MULT;
		mlx->x_max -= (ratio_x * (W - x)) * ZOOM_MULT;
		mlx->y_min += (ratio_y * (H - y)) * ZOOM_MULT;
		mlx->y_max -= (ratio_y * y) * ZOOM_MULT;
	}
	if (Button5 == button)
	{
		mlx->zoom_shift *= 1.10;
		mlx->x_min -= (ratio_x * x) * ZOOM_MULT;
		mlx->x_max += (ratio_x * (W - x)) * ZOOM_MULT;
		mlx->y_min -= (ratio_y * (H - y)) * ZOOM_MULT;
		mlx->y_max += (ratio_y * y) * ZOOM_MULT;
	}
	ft_fractol_render(mlx);
	return (0);
}

/**
 * ft_key_hooks - in the event of keypress, this function
 * checks for the keysym of the pressed key, and compare it
 * with the MACRO available on X11/keysym.h header file
 * @keysym: abstract representation of a keyboard key
 * @mlx: pointer to Mlx Data
 * Return: void
*/
static int	ft_key_hooks(int keysym, t_mlx_data *mlx)
{
	if (XK_Escape == keysym)
		ft_close(mlx);
	else if (XK_Left == keysym)
		mlx->shift_x += 0.5 * mlx->zoom_shift;
	else if (XK_Up == keysym)
		mlx->shift_y -= 0.5 * mlx->zoom_shift;
	else if (XK_Down == keysym)
		mlx->shift_y += 0.5 * mlx->zoom_shift;
	else if (XK_Right == keysym)
		mlx->shift_x -= 0.5 * mlx->zoom_shift;
	else if (XK_L_PLUS == keysym || XK_R_PLUS == keysym)
	{
		mlx->max_iteration += 10;
		mlx->max_val_col += 1;
	}
	else if (XK_minus == keysym || XK_R_MINUS == keysym)
	{
		mlx->max_iteration -= 10;
		mlx->max_val_col -= 1;
	}
	ft_fractol_render(mlx);
	return (0);
}
