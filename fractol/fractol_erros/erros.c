/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:15:33 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/31 18:15:35 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * ft_printf_error - prints an error on stderr
 * in case of an error occurs and exit the program
 * with EXIT_FAILURE status.
 * @error: pointer to error msg
 * Return: void.
*/
void	ft_print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	ft_perror(t_mlx_data *mlx)
{
	free(mlx->mlx_connection);
	perror("Fractol: ");
	exit(EXIT_FAILURE);
}
