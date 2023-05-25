#include "shell.h"

/**
 * _execute - Executes the specified command by forking a new process
 * @args: Array of arguments
 * Return: Exit status of command
 */
void _echo(char **args);

int _execute(char **args)
{
	pid_t process_id;
	int exit_status, process_status = 0;
	char exec_err[] = "Error: Unable to execute command.\n";

	if (_strcmp(args[0], "echo") == 0)
	{
		_echo(args);
		return (0);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		_cd(args);
		return (0);
	}

	process_id = fork();
	if (process_id == -1)
	{
		char fork_err[] = "Error: Forking process failed.\n";

		write(STDERR_FILENO, fork_err, sizeof(fork_err) - 1);
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{

		execvp(args[0], args);
		write(STDERR_FILENO, exec_err, sizeof(exec_err) - 1);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(process_id, &process_status, 0);
		if (WIFEXITED(process_status))
			exit_status = WEXITSTATUS(process_status);
	}
	return (exit_status);
}

/**
 *  * _echo - Echo command
 * @args: Array of arguments
 *
 */

void _echo(char **args)
{
	int i = 1;
	char newline = '\n';
	size_t len;


	while (args[i] != NULL)
	{
		char *arg = args[i];

		len = 0;

		while (arg[len] != '\0')
			len++;

		write(STDOUT_FILENO, arg, len);
		write(STDOUT_FILENO, " ", 1);
		i++;
	}
	write(STDOUT_FILENO, &newline, 1);
}

