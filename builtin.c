#include "shell.h"

/**
 * env_builtin - prints the environment variables.
 *
 */

void env_builtin(void)
{
	int z = 0;

	for	(z = 0; environ[z] != NULL; ++z)
	{
		write(STDOUT_FILENO, environ[z], _strlen(environ[z]));
		write(STDOUT_FILENO, "\n", 1);
		z++;
	}
}
