#include "./pipex.h"

static int	ft_check_sep(char c, char sep)
{
	return (c == sep);
}

static int	ft_strings(const char *s, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[count])
	{
		while (s[count] && ft_check_sep(s[count], sep))
			count++;
		if (s[count])
			i++;
		while (s[count] && !ft_check_sep(s[count], sep))
			count++;
	}
	return ((int)i);
}

static int	ft_strtosep(const char *s, char sep)
{
	int	count;

	count = 0;
	while (s[count] && !ft_check_sep(s[count], sep))
		count++;
	return (count);
}

static char	*ft_put_word(const char *s, char sep, char **dup, int i)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strtosep(s, sep);
	dup[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup[i])
	{
		while (--i >= 0)
		{
			free(dup[i]);
		}
		free(dup);
		return (NULL);
	}
	while (count < len)
	{
		dup[i][count] = s[count];
		count++;
	}
	dup[i][count] = '\0';
	return (dup[i]);
}

char	**ft_split(const char *s, char c)
{
	char	**av;
	int		count;

	count = 0;
	av = (char **)malloc(sizeof(char *) * (ft_strings(s, c) + 1));
	if (!av)
		return (NULL);
	while (*s)
	{
		while (*s && ft_check_sep(*s, c))
			s++;
		if (*s)
		{
			if (ft_put_word(s, c, av, count) == NULL)
				return (NULL);
			count++;
		}
		while (*s && !ft_check_sep(*s, c))
			s++;
	}
	av[count] = NULL;
	return (av);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

/**
 * ft_strcpy - function that copies bytes's src into dst
 * @src: source
 * @dst: destination
 * Return: void.
*/
static void	ft_strcpy(char *dst, const char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
}

/**
 * ft_strjoin - function that concatenates s1 and s2
 * and allocate memory for the new string.
 * @s1: The prefix string
 * @s2: The suffix string
 * Return: The new string, othewise NULL
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	int		len;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	if (s2 != NULL)
		len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	new_str = malloc(sizeof(*new_str) * len + 2); // add 1 in the allocation for '/'
	if (new_str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(new_str, s1);
	new_str[len_s1] = '/';
	if (s2 != NULL)
		ft_strcpy(new_str + len_s1 + 1, s2);
	return (new_str);
}
