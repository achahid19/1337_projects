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

/* conversion function's prototypes */
int		(*ft_get_func(char c))(va_list args);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_putnbr(va_list args);
int		ft_percent(va_list args);
int		ft_unsigned_nbr(va_list args);
int		ft_printlow_hexa(va_list args);
int		ft_printup_hexa(va_list args);
int		ft_print_pointer(va_list args);

/* helper functions prototypes */
void	ft_conversion(const char *format, size_t *len, va_list args);
int		ft_check_specifier(char c);
void	ft_negative(long int *l, char *buffer, size_t *n);
void	ft_zero(char *buffer, size_t *n);
void	ft_length(size_t l, size_t *n);
int		ft_printlow_hex(unsigned long int n);

/* libft's functions */
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	ft_strrev(char *str);

/* Struct to get the corresponding function, depending in format identifier */
typedef struct s_get_func
{
	char	c;
	int		(*f)(va_list);
}	t_get_func;

#endif /* FT_PRINTF_H */
