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
		exit(EXIT_FAILURE);
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
void	ft_fractol_hooks_loop(t_mlx_data *mlx)
{
	mlx_key_hook(mlx->mlx_win, &ft_key_hooks, mlx);
	/* mlx_mouse_hook(mlx->mlx_win, &cross_func, mlx); */ // TODO the cross button.
	mlx_loop(mlx->mlx_connection);
}
