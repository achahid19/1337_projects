#include "./pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

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

int main(int ac, char *av[], char *envp[])
{
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**args;
	char	*path;

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
		args = ft_split(av[1], ' ');
		path = ft_addpath(path, args[0]); // add the command PATH
		if (execve(path, args, NULL) == -1) /* how I can redirect the output of execve ? */
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
	printf("%s\n", getenv("PATH"));
	close(end[0]);
	close(end[1]);
	if (waitpid(pid1, NULL, 0) != -1) // Make the main process waits for his child
		printf("Waited for the child");
	waitpid(pid2, NULL, 0);
	
	return (0);
}
