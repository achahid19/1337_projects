/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:44:57 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/10 18:44:59 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * ft_error_print - print an error message to stderr
 * @msg: message to print
 * Return: exit program execution with status of 1.
*/
int	ft_error_print(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

/**
 * ft_exit_failure - exit the program execution with error
 * Return: exit status
*/
int	ft_error_exit(void)
{
	perror("\033[31mError");
	exit(1);
}

/**
 * ft_get_path - search in in envp matrice for the PATH variable
 * @envp: 2D array of environement's variables
 * Returs: PATH variable
*/
char	*ft_get_path(char **envp)
{
	size_t	count;

	count = 0;
	
	while (ft_strncmp(envp[count], "PATH", 4) != 0)
	{
		count++;
		if (ft_strncmp(envp[count], "PATH", 4) == -1)
			return (NULL);
	}
	return (envp[count]);
}

/**
 * ft_execute_cmd - function that search for the path of the cmd 
 * and make sure that the file of the cmd is and executable
 * @cmd: command for which we search the path in envp
 * @envp: holds the environment's variables
 * Return: Path to the command, otherwise NULL
*/
char	*ft_find_cmd(char *cmd, char **envp)
{
	char	**token;
	char	**path;
	char	*path_to_cmd;
	char	*env;
	size_t	i;

	path_to_cmd = NULL;
	i = 0;
	env = ft_get_path(envp);
	if (env == NULL)
		return (NULL);
	token = ft_split(cmd, ' ');
	path = ft_split(env, ':');
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], token[0]);
		if (access(path[i], X_OK) == 0)
		{
			path_to_cmd = path[i];
			break ;
		}
		i++;
	}
	return (path_to_cmd);
}
