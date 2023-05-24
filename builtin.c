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

/**
 * setenv_builtin - sets or modifies an environment variable
 * @args: Array of command arguments [0] -> "setenv",
 * [1] -> VARIABLE, [2] -> VALUE
 *
 * Return: 0 on success, -1 on failure
 */
int setenv_builtin(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n",
				_strlen("Usage: setenv VARIABLE VALUE\n"));
		return (-1);
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set environment variable.\n",
				_strlen("Failed to set environment variable.\n"));
		return (-1);
	}
	return (0);
}

/**
 * unsetenv_builtin - removes an environment variable
 * @args: Array of command arguments [0] -> "unsetenv",
 * [1] -> VARIABLE
 *
 * Return: 0 on success, -1 on failure
 */
int unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n",
				_strlen("Usage: unsetenv VARIABLE\n"));
		return (-1);
	}

	if (unsetenv(args[1]) != 0)
	{
		write(STDERR_FILENO, "Failed to unset environment variable.\n",
				_strlen("Failed to unset environment variable.\n"));
		return (-1);
	}
	return (0);
}
