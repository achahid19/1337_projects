#include "../ft_printf.h"

/**
 * ft_strlen - function that counts the length of str
 * @str: string
 * Return: the length of the string
*/
size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
