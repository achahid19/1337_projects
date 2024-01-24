/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:02:16 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/23 13:02:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// ./a.out Julia <real> <imaginary> || ./a.out Mandelbrot
// Display the parameters available if invalid
// Use color for depth of each fractal
// hooks: zoom, ESC quit and clean also for clicking the cross (x) 
// use of image is mandatory

int main(int ac, char **av)
{
	t_mlx_data	mlx;

    if ((2 == ac && 0 == ft_strncmp(av[1], "Mandelbrot", 10))
		|| (4 == ac && 0 == ft_strncmp(av[1], "Julia", 5)))
	{
		// Construct the MLX data and render stuff.
		ft_fractol_init(&mlx, av[1]);
		ft_fractol_render(&mlx);
		ft_fractol_hooks_loop(&mlx, av[1]);
	}
	else
	{
		write(2, INVALID_PARA, ft_strlen(INVALID_PARA));
		exit(EXIT_FAILURE);
	}
}
