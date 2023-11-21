#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ft_printf's prototype */
int	ft_printf(const char *format, ...);

/* helpers function's prototypes */
int		(*ft_get_func(char c))(va_list args);
int		ft_check_specifier(char c);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_putnbr(va_list args);
size_t	ft_strlen(char *str);
int		ft_putc(int c);
int		ft_percent(va_list args);

/* Struct to get the corresponding function, depending in format identifier */
typedef struct get_func_s
{
	char c;
	int (*f)(va_list);
} get_func_t;

#endif /* FT_PRINTF_H */
