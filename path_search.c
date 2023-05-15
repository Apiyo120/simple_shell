#include "shell.h"

/**
 * _find_path - searches for the path of the given command
 * @command: name of command
 * @env: environment variables
 *
 * Return: full path of the command if found
 * NULL otherwise
 */
char *_find_path(char *command, char **env)
{
	char *path = _getenv("PATH", env);
	char *path_token = NULL, *command_path = NULL, *path_copy = NULL;
	struct stat st;

	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	path_token = strtok(path_copy, ":");
	while (path_token)
	{
		command_path = _strcat(path_token, "/");
		if (!command_path)
		{
			free(path_copy);
			return (NULL);
		}
		command_path = _strcat(command_path, command);
		if (!command_path)
		{
			free(path_copy);
			return (NULL);
		}
		if (stat(command_path, &st) == 0)
			break;
		free(command_path);
		command_path = NULL;
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (!command_path)
		return (NULL);
	if (stat(command_path, &st) == -1)
	{
		free(command_path);
		return (NULL);
	}
	return (command_path);
}
