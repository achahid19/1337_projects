#include "ft_printf.h"

/**
 * ft_printf - function that processes the format string and format
 * the ouptut depending on the format specifier
 * @format: the format string
 * Return: length of formated output, otherwise -1 if fails
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	size_t	len;
	int		(*f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	count = 0;
	len = 0;
	while (format[count])
	{
		if (format[count] != '%')
			write (1, &format[count], 1);
		else if (format[count] == '%')
		{
			if (!ft_check_specifier(format[count + 1])) /* if *format not match any specifier */
			{
				write (1, &format[count++], 1);
				continue;
			}
			count++;
			len -= 2;
			f = ft_get_func(format[count]);
			len += (*f)(args);
		}
		count++;
	}
	va_end(args);
	return (count + len);
}
