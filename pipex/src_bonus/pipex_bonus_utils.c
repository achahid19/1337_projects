/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:49:07 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/13 09:49:08 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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
 * free_all - free all the 2d array
 * @av: pointer to the 2D array
 * Return: void
*/
void	free_all(char **av)
{
	int	count;

	count = 0;
	while (av[count] != NULL)
		free(av[count++]);
	free(av);
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
	t_type	obj;

	obj.path_to_cmd = NULL;
	obj.i = 0;
	obj.env = ft_get_path(envp);
	if (obj.env == NULL)
		return (NULL);
	obj.token = ft_split(cmd, ' ');
	obj.path = ft_split(obj.env, ':');
	while (obj.path[obj.i] != NULL)
	{
		obj.path[obj.i] = ft_strjoin(obj.path[obj.i], obj.token[0]);
		if (access(obj.path[obj.i], X_OK) == 0)
		{
			obj.path_to_cmd = ft_strdup(obj.path[obj.i]);
			if (obj.path_to_cmd == NULL)
				return (NULL);
			break ;
		}
		obj.i++;
	}
	return (free_all(obj.path), free_all(obj.token), obj.path_to_cmd);
}

/**
 * ft_cmd_path - get the path of the cmd from the cmd itself
 * @cmp_path: pointer to the command with its paht
 * Return: The path of cmd separeted from the arguments.
*/
char	*ft_cmd_path(char *cmd_path)
{
	int		count;
	char	*cmd;
	int		index;

	count = 0;
	while (cmd_path[count] != ' ' && cmd_path[count])
		count++;
	cmd = (char *)malloc(sizeof(char) * count + 1);
	if (cmd == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		cmd[index] = cmd_path[index];
		index++;
	}
	cmd[index] = '\0';
	return (cmd);
}
