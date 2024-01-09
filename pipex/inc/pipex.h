#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char **ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_putendl_fd(char *str, int fd);

int		ft_error_print(char *msg);
int		ft_error_exit(void);
char	*ft_get_path(char **envp);
char	*ft_find_cmd(char *cmd, char **envp);
void	ft_child1_process(char **av, char **envp, int *end);
void	ft_child2_process(char **av, char **envp, int *end);

typedef struct s_type {
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
} t_type;

#endif /* PIPEX_H */
