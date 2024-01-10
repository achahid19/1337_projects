#include "../inc/pipex.h"

/**
 * ft_child1_process - execute the 1st child's cmd and write it through the write end of the pipe
 * @av: program's arguments
 * @envp: variables of the environement
 * @end: pointer to the pipe that makes communications between processes
 * Return: void.
*/
void	ft_child1_process(char **av, char **envp, int *end)
{
	int		file1;
	char	*path_to_cmd = NULL;
	char	**cmd;

	file1 = open(av[1], O_RDONLY);
	if (file1 == -1)
		ft_error_exit();
	dup2(end[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(end[0]);
	close(end[1]);
	cmd = ft_split(av[2], ' ');
	path_to_cmd = ft_find_cmd(av[2], envp);
	if (path_to_cmd == NULL)
		ft_error_print("\033[1;31mError:]: Command not found!\033[0m");
	if (execve(path_to_cmd, cmd, envp) == -1)
		ft_error_exit();
}

/**
 * ft_child2_process - execute the 2end child's cmd (the input is readed through the reading end of the pipe)
 * @av: program's arguments
 * @envp: 2D array of environement's variables
 * @end: pointer to the pipe that handles communicutions between the child1 and child2
 * Return: void.
*/
void	ft_child2_process(char **av, char **envp, int *end)
{
	int		file2;
	char	*path_to_cmd;
	char	**cmd;
	
	file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		ft_error_exit();
	dup2(end[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(end[1]);
	close(end[0]);
	cmd = ft_split(av[3], ' ');
	path_to_cmd = ft_find_cmd(av[3], envp);
	if (path_to_cmd == NULL)
		ft_error_print("\033[1;31mError:]: Command not found!\033[0m");
	if (execve(path_to_cmd, cmd, envp) == -1)
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
		return (ft_error_print("\033[1;31mError: Bad number of arguments!\033[0m"));
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
