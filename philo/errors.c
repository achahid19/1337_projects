/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:56:54 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:56:55 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(const char *error);

/**
 * print_error
*/
void	print_error(const char *error)
{
	write(2, error, ft_strlen(error));
	exit(-1);
}
