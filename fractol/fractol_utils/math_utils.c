/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:40:40 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/31 09:40:41 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_decimal_count(t_var *atoi, const char *str);
static void	ft_atoi_handler(const char *str, t_var *atoi);

/**
 * ft_atoi - convert string to float
 * @str: string to convert
 * Return: floating number
*/
double	ft_atoi(const char *str)
{
	t_var	atoi;

	atoi.count = 0;
	atoi.sign = 1;
	atoi.result = 0;
	atoi.div = 1;
	if (str[atoi.count] == '-' || str[atoi.count] == '+')
	{
		if (str[atoi.count] == '-')
			atoi.sign = -atoi.sign;
		atoi.count++;
	}
	if (!(str[atoi.count] >= '0' && str[atoi.count] <= '9')
		&& !(str[atoi.count] == '.'))
		ft_print_error("\033[1;33mError: Bad argument!\033[0m");
	while ((str[atoi.count] >= '0' && str[atoi.count] <= '9')
		|| (str[atoi.count] == '.'))
	{
		ft_atoi_handler(str, &atoi);
		atoi.count++;
	}
	return ((atoi.result / atoi.div) * atoi.sign);
}

/**
 * ft_decimal_count - counts number of decimals
 * @atoi: pointer to atoi's variables
 * @str: string to convert
 * Return: void.
*/
static void	ft_decimal_count(t_var *atoi, const char *str)
{
	atoi->div = 10;
	atoi->count1 = atoi->count + 1;
	atoi->div_count = 1;
	while (str[atoi->count1] >= '0' && str[atoi->count1] <= '9')
	{
		atoi->count1++;
		atoi->div_count++;
	}
	atoi->div_count--;
	atoi->count1 = 1;
	while (atoi->count1 < atoi->div_count)
	{
		atoi->div = atoi->div * 10;
		atoi->count1++;
	}
}

static void	ft_atoi_handler(const char *str, t_var *atoi)
{
	if (str[atoi->count] != '.')
		atoi->result = atoi->result * 10 + (str[atoi->count] - 48);
	else if (str[atoi->count] == '.')
	{
		if (str[atoi->count + 1] == '.' || !(str[atoi->count + 1] >= '0'
				&& str[atoi->count + 1] <= '9'))
			ft_print_error("\033[1;33mError: Bad argument!\033[0m");
		ft_decimal_count(atoi, str);
	}
}

/**
 * ft_pixel_scale - scale a number to fit some specific metrics
 * @unscaled_num: number to be scaled
 * @new_min: the new minimum value
 * @new_max: the new maximum value
 * @old_min: the old minimum value
 * @odl_max: the old maximum value
 * Return: scaled number.
*/
double	ft_scale(double unscaled_num, double n_min, double n_max, double o_max)
{
	double	o_min;

	o_min = 0.0;
	return ((n_max - n_min) * (unscaled_num - o_min) / (o_max - o_min) + n_min);
}
