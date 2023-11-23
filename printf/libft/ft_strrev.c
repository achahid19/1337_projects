#include "../ft_printf.h"
/**
 * ft_strrev - function that reverses the indexs of an array
 * @str: pointer to the string to reverse
 * Return: void.
*/

void	ft_strrev(char *str)
{
	size_t	len;
	size_t	count;
	char	temp;

	len = ft_strlen(str) - 1;
	count = 0;
	while (count < len)
	{
		temp = str[count];
		str[count++] = str[len];
		str[len--] = temp;
	}
}
