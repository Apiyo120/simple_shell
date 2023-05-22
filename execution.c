#include "shell.h"

/**
 * _execute - Executes the specified command by forking a new process
 * @args: Array of arguments
 * Return: Exit status of command
 */
int _execute(char **args)
{
	pid_t process_id;
	int exit_status, process_status = 0;
	char exec_err[] = "Error: Unable to execute command.\n";

	if (access(args[0], X_OK) == -1)
	{
		char file_err[] = "Error: Unable to open file: ";
		char newline = '\n';

		write(STDERR_FILENO, file_err, sizeof(file_err) - 1);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, &newline, 1);

		return (EXIT_FAILURE);
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
