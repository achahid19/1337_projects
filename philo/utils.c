#include "philo.h"

size_t		ft_strlen(const char *str);
long		ft_atol(const char *str);

/**
 * ft_strlen - Get the length of str
 * @str: pointer to the string
 * 
 * Return: string's length
*/
size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*(str + length))
		length++;

	return (length);
}

/**
 * ft_atol - converts a string to a long intger
 * @str: pointer to the string
 * 
 * Return: long integer.
*/
long	ft_atol(const char *str)
{
	int			sign;
	long		result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}

	return (result * sign);
}
