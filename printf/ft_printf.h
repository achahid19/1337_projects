/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:48:51 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/22 11:48:53 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ft_printf's prototype */
int		ft_printf(const char *format, ...);

/* helpers function's prototypes */
int		(*ft_get_func(char c))(va_list args);
int		ft_check_specifier(char c);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_putnbr(va_list args);
int		ft_putc(int c);
int		ft_percent(va_list args);
size_t	ft_strlen(char *str);
void	ft_conversion(const char *format, size_t *len, va_list args);
/* Struct to get the corresponding function, depending in format identifier */
typedef struct s_get_func
{
	char	c;
	int		(*f)(va_list);
}	t_get_func;

#endif /* FT_PRINTF_H */
