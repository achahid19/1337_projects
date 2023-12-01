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
#include <fcntl.h>
/**
 * get_next_line - function that reads a line by line form a fd
 * @fd: file descriptor
 * Return: the line readed from the fd
*/
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*buffer; /* initialized automaticly to 0 in bss */
	char	*bytes_readed;
	ssize_t	bytes_count;
	static int	count = 0;

	bytes_count = 1;
	printf("WE ARE IN CALL: %d\n", count);
	printf("--------------------------------------\n");
/* 	if (count > 0) freeing the buffer of the previous line if a while loop is used
	{
		free (buffer);
		printf("freed\n");
	} */
	buffer = NULL;
	printf("buffer1: %s, in call: %d\n", buffer, count);
	count++;
	if (fd < 0 || BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_readed = (char *)malloc(BUFFER_SIZE + 1);
	if (bytes_readed == NULL)
		return (NULL);
	while (bytes_count != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_count = read(fd, bytes_readed, BUFFER_SIZE); /* the read function moves * if a byte is readed */
		printf("%ld bytes readed in call: %d\n", bytes_count, count);
		if (bytes_count == -1)
		{
			free(bytes_readed);
			free(buffer);
			return (NULL);
		}
		bytes_readed[bytes_count] = '\0';
		buffer = ft_strjoin(buffer, bytes_readed);
		if (buffer == NULL)
			return (NULL);
		printf("call: %d and str: %s\n", count, buffer);
	}
	free(bytes_readed);
	return (buffer);
}

int main(void)
{
	int		fd = open("test.txt", O_CREAT, "rw");
	int		cd = open("test1.txt", O_CREAT, "rw");
	char	*str;
	char	*ptr;
	for (size_t count = 0; count < 2; count++)
	{
		str = get_next_line(fd);
		printf("str: %s\n", str);
		free(str);
		ptr = get_next_line(cd);
		printf("ptr: %s\n", ptr);
		free(ptr);
	}
/* 	str = get_next_line(fd);
	printf("str: %s\n", str);
	free(str);
	close(fd);
	close(cd); */
	return (0);
}
