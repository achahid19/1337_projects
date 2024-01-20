/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:45:46 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/10 18:45:47 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * ft_child1_process - execute the 1st child's cmd and write it
 * through the write end of the pipe
 * @av: program's arguments
 * @envp: variables of the environement
 * @end: pointer to the pipe that makes communications between processes
 * Return: void.
*/
void	ft_child1_process(char **av, char **envp, int *end)
{
	int		infile;
	char	*path_to_cmd;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error_exit();
	dup2(end[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(end[0]);
	close(end[1]);
	close(infile);
	if (ft_strncmp(av[2], "/", 1) == 0)
	{
		path_to_cmd = ft_cmd_path(av[2]);
		if (access(path_to_cmd, X_OK) == 0)
			execve(path_to_cmd, ft_split(av[2], ' '), envp);
		else
			free_and_exit("\033[1;31mPath1 Not Found!\033[0m", path_to_cmd);
	}
	path_to_cmd = ft_find_cmd(av[2], envp);
	if (path_to_cmd == NULL)
		ft_error_print("\033[1;33mError:]: Cmd1 not found!\033[0m");
	if (execve(path_to_cmd, ft_split(av[2], ' '), envp) == -1)
		ft_error_exit();
}

/**
 * ft_child2_process - execute the 2end child's cmd
 * (the input is readed through the reading end of the pipe)
 * @av: program's arguments
 * @envp: 2D array of environement's variables
 * @end: pointer to the pipe that handles communicutions between
 * the child1 and child2
 * Return: void.
*/
void	ft_child2_process(char **av, char **envp, int *end)
{
	int		outfile;
	char	*path_to_cmd;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error_exit();
	dup2(end[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(end[1]);
	close(end[0]);
	if (ft_strncmp(av[3], "/", 1) == 0)
	{
		path_to_cmd = ft_cmd_path(av[3]);
		if (access(path_to_cmd, X_OK) != -1)
			execve(path_to_cmd, ft_split(av[3], ' '), envp);
		else
			free_and_exit("\033[1;31mPath2 Not Found!\033[0m", path_to_cmd);
	}
	path_to_cmd = ft_find_cmd(av[3], envp);
	if (path_to_cmd == NULL)
		ft_error_print("\033[1;33mError:]: Cmd2 not found!\033[0m");
	if (execve(path_to_cmd, ft_split(av[3], ' '), envp) == -1)
		ft_error_exit();
}

/**
 * main - Entry point
 * Description: create the pipe of shell
 * Return: Always 0 (Success)
*/
int	main(int ac, char **av, char **envp)
{
	t_type	obj;

	if (ac != 5)
		return (ft_error_print("\033[1;31mError: Bad arguments!\033[0m"));
	else
	{
		if (pipe(obj.end) == -1)
			ft_error_exit();
		obj.pid1 = fork();
		if (obj.pid1 < 0)
			ft_error_exit();
		else if (obj.pid1 == 0)
			ft_child1_process(av, envp, obj.end);
		obj.pid2 = fork();
		if (obj.pid2 < 0)
			ft_error_exit();
		else if (obj.pid2 == 0)
			ft_child2_process(av, envp, obj.end);
		close(obj.end[0]);
		close(obj.end[1]);
		waitpid(obj.pid1, NULL, 0);
		waitpid(obj.pid2, NULL, 0);
	}
	return (0);
}
