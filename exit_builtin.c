#include "shell.h"

/**
 * _exit_builtin - exits the shell.
 * @arg: arguments
 */

void _exit_builtin(char *arg)
{
	int status;

	if (arg == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		status = atoi(arg);
		exit(status);
	}
}
