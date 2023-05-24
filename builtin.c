#include "shell.h"

/**
 * _env_builtin - prints the environment variables.
 *
 */

void _env_builtin(void)
{
	int z = 0;
	char newline = '\n';
	size_t len;

	while (environ[z] != NULL)
	{
		len = _strlen(environ[z]);

		write(STDOUT_FILENO, environ[z], len);
		write(STDOUT_FILENO, &newline, 1);

		z++;
	}
}
