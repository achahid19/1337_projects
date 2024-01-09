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
char *ft_get_path(char **envp)
{
	size_t count;

	count = 0;
	while (ft_strncmp(envp[count], "PATH", 4) != 0)
		count++;
	return (envp[count]);
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
