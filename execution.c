#include "shell.h"

/**
 * _execute - executes a command with arguments.
 * @args: command and arguments.
 * @path: full path of the command.
 * @env: environment variables.
 *
 * Return: 0 on success, 1 on failure
 */

int _execute(char **args, char *path, char **env)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();


	if	(pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		if	(execve(path, args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (status);
}
