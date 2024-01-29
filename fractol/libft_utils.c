#include "fractol.h"

/**
 * ft_strncmp - compares n bytes between s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compares
 * Return: 0 if s1 == s2, > 0 if s1 > s2, othwise < 0 if s1 < s2
*/
int ft_strncmp(const char *s1, const char *s2, int n)
{
    if (!s1 || !s2 || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        s1++;
        s2++;
        --n;
    }
    return (*s1 - *s2);
}

/**
 * ft_strlen - counts the length of str
 * @str: string
 * Return: length of str
*/
size_t  ft_strlen(const char *str)
{
    /* base case to stop the recursion */
    if (NULL == str || '\0' == *str)
        return (0);
    /* recursive case */
    return (ft_strlen(str + 1) + 1);
}
