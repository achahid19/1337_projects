#include "printf.h"

/**
 * ft_printf - function like printf, process the format string, parses
 * the format specifier and execute the formated output
 * @format: pointer to the format string
 * Return: length of formated output
*/
int	ft_printf(const char *format, ...)
{
	va_list	av;
	size_t	count;
	int		(*func)(va_list);
	size_t	len;

	len = 0;
	if (!format)
		return (-1);
	va_start(av, format);
	count = 0;
	while (format[count])
	{
		while (format[count] != '%' && format[count] != '\0')
			write (1, &format[count++], 1);
		while (format[count] == '%')
		{
			if (!ft_check_specifier(format[count + 1])) /* if is not a specifier */
			{
				write (1, &format[count++], 1);
				continue;
			}
			count++;
			len = -2;
			func = ft_get_specifier(format[count]);
			len += func(av);
		}
	}
	return (count + len);
}
