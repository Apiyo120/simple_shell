#include "shell.h"

/**
 * _is_builtin - check if a command is a built-in
 * @args: array of arguments
 *
 * Return: 1 if built-in, 0 otherwise
 */

int _is_builtin(char **args)
{
	if (!args || !args[0])
		return (0);

	if (_strcmp(args[0], "exit") == 0 ||
		_strcmp(args[0], "env") == 0)
		return (1);

	return (0);
}

/**
 * _execute_builtin - execute a built-in command
 * @args: array of arguments
 * @env: copy of environment variables
 *
 * Return: exit status of the command
 */

int _execute_builtin(char **args, char **env)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			return (_atoi(args[1]));

		_free_env(env);
		free(args);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		_print_env(env);
			return (0);
	}
	return (-1);
}
