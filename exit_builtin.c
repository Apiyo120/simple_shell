#include "shell.h"

/**
 * _exit_builtin - exits the shell.
 *@status: The exit status to be used for exiting the shell.
 */

void _exit_builtin(int status)
{
	exit(status);
}
