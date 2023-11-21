#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* prototype of the printf-like function */
int	ft_printf(const char *, ...);

/* prototype of the helper function to make ft_printf functional */
int	ft_putchar(va_list av);
int ft_putnbr(va_list av);
int ft_putstr(va_list av);
int	ft_check_specifier(char c);
int (*ft_get_specifier(char c))(va_list);

/* struct to get the correspending function, depending on the format specifier */
typedef struct conversion_s
{
	char c;
	int (*f)(va_list av);
} conversion_t;

#endif /* PRINTF_H */
