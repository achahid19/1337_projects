#include "./pipex.h"
#include "libft/libft.h"

typedef struct s_type {
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
} t_type;

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
char *ft_get_path(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4) != 0)
		**envp++;
	return (*envp);
}

/**
 * ft_execute_cmd - function that search for the path of the cmd and make sure that the file of the cmd is and executable
 * @cmd: command for which we search the path in envp
 * @envp: holds the environment's variables
 * Return: Path to the command, otherwise NULL
*/
char	*ft_find_cmd(char *cmd, char **envp)
{
	char **token;
	char **path;
	char *path_to_cmd;
	char *env;
	size_t i;

	env = ft_get_path(envp);
	i = 0;
	path_to_cmd = NULL;
	/* first we need to split the cmd array into a 2d array for execve func */
	token = ft_split(cmd, ' ');
	/* the we move the env to 2D array too */
	path = ft_split(env, ':');
	/* then have to join the cmd in each path of the PATH variable */
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], token[0]);
		i++;
	}
	/* Since we have the full Path where to seatch the exec, we can know check for the exec if there is in any path */	
	i = 0;
	while (access(path[i], X_OK) != 0) /**
										* F_OK checks for if the file exist in the PATH or not
										* we need to check if the cmd file is an executable or not
										* so should work with X_OK
										*/
	{
		i++;
		if (access(path[i], X_OK) == 0)
			path_to_cmd = path[i];
	}
	return (path_to_cmd);
}
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
	char	*path_to_cmd;
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
