/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:45:45 by achahid-          #+#    #+#             */
/*   Updated: 2023/12/01 08:45:50 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	new_line_finder(char *str);
static char		*substr(char *str);
static char		*get_line(char *str);
static void		free_buffers(char *s1, char *s2);

/**
 * get_next_line - function that reads a line by line form a fd
 * @fd: file descriptor
 * Return: the line readed from the fd
*/
char	*get_next_line(int fd)
{
	static char	*buffer; /* initialized automaticly to 0 in bss */
	char		*bytes_readed;
	ssize_t		bytes_count;

	bytes_count = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bytes_readed = (char *)malloc(BUFFER_SIZE + 1);
	if (bytes_readed == NULL)
		return (NULL);
	while (bytes_count != 0 && !ft_strchr(buffer, '\n')) /* bytes_count != 0 for EOF */
	{
		bytes_count = read(fd, bytes_readed, BUFFER_SIZE); /* the read function moves * if a byte is readed */
		if (bytes_count == -1)
		{
			free_buffers(bytes_readed, buffer);
			return (NULL);
		}
		bytes_readed[bytes_count] = '\0';
		buffer = ft_strjoin(buffer, bytes_readed);
	}
	free(bytes_readed);
	bytes_readed = get_line(buffer);
	buffer = substr(buffer); /* this is the value I asign to buffer to make several calls */
	return (bytes_readed);
}

/**
 * new_line_finder - function that search for new line in str or eof
 * @str: the string
 * Return: index of the byte after '\n' or index of eof
*/
static size_t	new_line_finder(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	if (*(str + count) == '\n')
		count++;
	return (count);
}

/**
 * substr - function that allocates memory to create a substring
 * @str: the string from where the substr is created
 * Return: the substring, othewise NULL
*/
static char	*substr(char *str)
{
	char	*substr;
	size_t	count;
	size_t	count1;

	count = 0;
	count1 = 0;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	count = new_line_finder(str);
	substr = (char *)malloc((ft_strlen(str) - count) + 1);
	if (substr == NULL)
		return (NULL);
	while (str[count])
		substr[count1++] = str[count++];
	substr[count1] = '\0';
	if (*substr == '\0')
	{
		free(substr);
		free(str);
		return (NULL);
	}
	free(str);
	return (substr);
}

/**
 * get_line - function that allocate memory to retrieve a line from str
 * @str: the string form where the line is retrieved
 * Return: the line, otherwise NULL
*/
static char	*get_line(char *str) /* DONE */
{
	char	*new_line;
	size_t	count;

	count = 0;
	if (!str || *str == '\0')
		return (NULL);
	count = new_line_finder(str);
	new_line = (char *)malloc(count + 1);
	if (new_line == NULL)
		return (NULL);
	count = 0;
	while (str[count] && str[count] != '\n')
	{
		new_line[count] = str[count];
		count++;
		if (str[count] == '\n')
		{
			new_line[count] = str[count];
			count++;
			break;
		}
	}
	new_line[count] = '\0';
	return (new_line);
}

/**
 * free_buffers - function that frees buffers
 * @s1: first buffer
 * @s2: second buffer
 * Return: void.
*/
static void	free_buffers(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

int main(void)
{
	int fd = open("test.txt", O_CREAT, "rw");
	int st = open("test1.txt", O_CREAT, "rw");
	char *str, *ptr;

	for (int count = 0; count < 2; count++)
	{
		str = get_next_line(fd);
		printf("str: %s\n", str);
		free(str);
	/* 	ptr = get_next_line(st);
		printf("ptr: %s\n", ptr);
		free(ptr); */
	}
	close(fd);
	close(st);
	return (0);
}
