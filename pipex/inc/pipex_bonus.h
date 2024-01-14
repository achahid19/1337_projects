/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:48:36 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/13 09:48:41 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_putendl_fd(char *str, int fd);
char	*ft_strdup(const char *s1);

int		ft_error_print(char *msg);
int		ft_error_exit(void);
char	*ft_get_path(char **envp);
char	*ft_find_cmd(char *cmd, char **envp);
void	ft_child1_process(char **av, char **envp, int *end);
void	ft_child2_process(char **av, char **envp, int *end);
char	*ft_cmd_path(char *cmd_path);
void	dup_and_close(int *end, int i);

typedef struct s_var
{
	int		infile;
	int		outfile;
	pid_t	pid;
	pid_t	pid2;
	int		count;
}	t_var;

typedef struct s_type
{
	char	**token;
	char	**path;
	char	*path_to_cmd;
	char	*env;
	size_t	i;
}	t_type;

#endif /* PIPEX_H */
