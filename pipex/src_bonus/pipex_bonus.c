/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:50:11 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/13 09:50:13 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/**
 * ft_pipe - function that parses the command before being
 * executed ann redirect the stdin into the end[0] by the
 * parent process
 * @av: vector of arguments that contains cmds
 * @envp: pointer to variables of the environement
 * @cmd: index of the cmd in av
 * Return: void.
*/
void	ft_pipe(char **av, char **envp, int cmd)
{
	pid_t	child_pid;
	int		end[2];
	char	*path_to_cmd;

	if (pipe(end) == -1)
		ft_error_exit();
	child_pid = fork();
	if (child_pid == 0)
	{
		dup_and_close(end, 1);
		if (ft_strncmp(av[cmd], "/", 1) == 0)
		{
			if (access(ft_cmd_path(av[cmd]), X_OK) == 0)
				execve(ft_cmd_path(av[cmd]), ft_split(av[cmd], ' '), NULL);
			else
				ft_error_print("\033[1;31mError: Path Not Found!\033[0m");
		}
		path_to_cmd = ft_find_cmd(av[cmd], envp);
		if (path_to_cmd == NULL)
			ft_error_print("\033[1;33mError: Cmd not found!\033[0m");
		if (execve(path_to_cmd, ft_split(av[cmd], ' '), NULL) == -1)
			ft_error_exit();
	}
	else
		dup_and_close(end, 0);
}

/**
 * ft_last_child - execute the last cmd and redirect the output to an
 * outfile
 * @outfile_fd: integer representing outfile's fd
 * @av: double pointer to arguments
 * @envp: double pointer to environements variables
 * Return: void.
*/
void	ft_last_child(int outfile_fd, char **av, int ac, char **envp)
{
	char	*path_to_cmd;

	dup2(outfile_fd, STDOUT_FILENO);
	if (ft_strncmp(av[ac - 2], "/", 1) == 0)
	{
		if (access(ft_cmd_path(av[ac - 2]), X_OK) != -1)
			execve(ft_cmd_path(av[ac - 2]), ft_split(av[ac - 2], ' '), NULL);
		else
			ft_error_print("\033[1;31mError: Path Not Found!\033[0m");
	}
	path_to_cmd = ft_find_cmd(av[ac - 2], envp);
	if (path_to_cmd == NULL)
		ft_error_print("\033[1;33mError: Cmd not found!\033[0m");
	if (execve(path_to_cmd, ft_split(av[ac - 2], ' '), NULL) == -1)
		ft_error_exit();
}

/**
 * main - Entry point
 * Description: multi-proccessing handling like shell's pipe
 * Return: Always 0 (Success).
*/
int	main(int ac, char **av, char **envp)
{
	t_var	obj;

	if (ac < 5)
		return (ft_error_print("\033[1;31mError: Bad arguments!\033[0m"));
	obj.infile = open(av[1], O_RDONLY);
	obj.outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (obj.infile == -1 || obj.outfile == -1)
		ft_error_exit();
	dup2(obj.infile, 0);
	obj.count = 2;
	while (obj.count < ac - 2)
	{
		ft_pipe(av, envp, obj.count);
		obj.count++;
	}
	obj.pid2 = fork();
	if (obj.pid2 == 0)
		ft_last_child(obj.outfile, av, ac, envp);
	close(obj.infile);
	close(obj.outfile);
	wait(NULL);
	return (0);
}
