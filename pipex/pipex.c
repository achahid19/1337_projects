#include "./pipex.h"

char	*ft_addpath(char *path_to_cmd, char *cmd)
{
	char	path[] = "/usr/bin/";
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	path_to_cmd = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + ft_strlen(path)) + 1);
	while (path[index])
	{
		path_to_cmd[index] = path[index];
		index++;
	}
	while (cmd[index2])
		path_to_cmd[index++] = cmd[index2++];
	path_to_cmd[index] = '\0';
	return (path_to_cmd);
}

char *get_path(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4) != 0)
		**envp++;
	return (*envp);
}

char	*execute_cmd(char *cmd, char **envp)
{
	char **token;
	char **path;
	char *path_to_cmd;
	char *env;
	size_t i;

	env = get_path(envp);
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

int main(int ac, char *av[], char *envp[])
{
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd;
	char	*path;
	char *path_of_cmd;

	if (pipe(end) == -1) // Cheking if the pipe was created with no erros
		return (1); // replace this with exit status
	pid1 = fork();
	if (pid1 < 0) // Check if no errors occurs when forking the main process
		return (2);
	else if (pid1 == 0) // We are on the child process
	{
		dup2(end[1], STDOUT_FILENO); /* anything which goes to stdout,(such as through printf), comes out pipe[0].*/

		close(end[0]); // close reading end since we're writing
		close(end[1]); // closing the writing end because the dup2 duplicate the file
		
		path_of_cmd = execute_cmd(av[1], envp); /* build your own getenv *//*  <====  */ 
		cmd = ft_split(av[1], ' ');
		if (execve(path_of_cmd, cmd, envp) == -1) /* how I can redirect the output of execve ? */
			return (3); // unsuccessful call of execve
	}
	/* The next statements of code will not be executed, since the execve replace all the process */
	/* have to create the second child! */
	pid2 = fork();
	if (pid2 < 0)
		return (2);
	else if (pid2 == 0)
	{		
		dup2(end[0], STDIN_FILENO);
		close(end[1]);
		/**
		 * up to 4096 is writed before the process got suspended, until reading...
		*/
		close(end[0]);
		char **args2 = ft_split(av[2], ' ');
		char *path2 = ft_addpath(path2, args2[0]);
		execve(path2, args2, NULL);
	}
	/* close the pipe for the main process, cause the end[0] will still wait for data if we do not close it */
	close(end[0]);
	close(end[1]);
	if (waitpid(pid1, NULL, 0) != -1) // Make the main process waits for his child
		printf("Waited for the child");
	waitpid(pid2, NULL, 0);
	
	return (0);
}
