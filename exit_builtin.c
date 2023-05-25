#include "shell.h"

/**
 * _exit_builtin - exits the shell.
 * @arg: arguments
 */

void _exit_builtin(char *arg)
{
	if (arg == NULL)
		exit(EXIT_SUCCESS);
	else if (strcmp(arg, "SUCCESS") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(arg, "FAILURE") == 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (strcmp(arg, "ERROR") == 0)
	{
		exit(1);
	}
	else
	{
		write(STDERR_FILENO, arg, _strlen(arg));
		exit(1);
	}
}
