#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

char **ft_split(const char *s, char c);
static void	ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);


#endif
