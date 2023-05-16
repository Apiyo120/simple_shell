#include "shell.h"

/**
 * _free_args - Frees the memory allocated for a array of strings.
 * @args: The array of strings to free.
 */

void _free_args(char **args)
{
	int z;

	if	(args)
	{
		for	(z = 0; args[z]; z++)
			free(args[z]);
		free(args);
	}
}

/**
 * _free_path - Frees the memory allocated for a path string.
 * @path: The path string to free.
 */

void _free_path(char *path)
{
	if	(path)
		free(path);
}

/**
 * _free_env - Free the memory allocated for an array of environment variables.
 * @env: The array of an environment variable to free.
 */

void _free_env(char **env)
{
	int z;

	if	(env)
	{
		for	(z = 0; env[z]; z++)
			free(env[z]);
		free(env);
	}
}
