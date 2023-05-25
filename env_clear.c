#include "shell.h"
/**
 * _setenv - function is used to set or modify an environment variable.
 * with the specified name and value
 * @name: name of environment variable.
 * @value: value to be assigned to environment variable.
 * @overwrite: checks whether to overwrite or not
 *
 * Return: 0 on success, -1 if an error occurs.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid arguments for setenv. \n", 36);
		return (-1);
	}

	if (getenv(name) != NULL)
	{
		if (!overwrite)
			return (0);
	}
	if (setenv(name, value, 1) == -1)
	{
		write(STDERR_FILENO, "Error: Unable to set environment variable.\n", 44);
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - function is used to unset or remove an environment variable
 * with the specific name and value.
 * @name: name of environment to variable to unset
 *
 * Return: 0 on success, -1 if an error occurs.
 */

int _unsetenv(const char *name)
{
	if	(name == NULL)
	{
		write(STDERR_FILENO, "Error: Unable to unset environment to ariable.\n", 46);
		return (-1);
	}
	if (unsetenv(name) == -1)
	{
		write(STDERR_FILENO, "Error: Unable to unset environment variable.\n", 46);
		return (-1);
	}
	return (0);
}
