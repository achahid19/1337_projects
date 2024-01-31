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

/**
 * main - Entry point
 * Description: Construct the MLX data, handle hooks
 * and render available sets:
 * (Mandelbrot, Julia and Tricorn)
 * 
 * Return: 0 on Success.
*/
#include "inc/fractol.h"

int	main(int ac, char **av)
{
	t_mlx_data	mlx;

	if ((2 == ac && 0 == ft_strncmp(av[1], "Mandelbrot", 10))
		|| (4 == ac && 0 == ft_strncmp(av[1], "Julia", 5))
		|| (2 == ac && 0 == ft_strncmp(av[1], "Tricorn", 7)))
	{
		mlx.set_name = av[1];
		if (0 == ft_strncmp(mlx.set_name, "Julia", 4))
		{
			ft_check_julia_input(av[2], av[3]);
			mlx.x_julia = ft_atoi(av[2]);
			mlx.y_julia = ft_atoi(av[3]);
		}
		ft_fractol_init(&mlx, av[1]);
		ft_fractol_render(&mlx);
		ft_fractol_hooks_loop(&mlx);
	}
	else
	{
		write(2, INVALID_PARA, ft_strlen(INVALID_PARA));
		exit(EXIT_FAILURE);
	}
	return (0);
}
