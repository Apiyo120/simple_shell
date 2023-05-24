#include "shell.h"

/**
 * _find_path - Finds the full path of an executable file
 * @command: The command name for which to find the full path.
 *
 * Return:    A pointer to a dynamically allocated string
 *            containing the full path of the executable file, or
 *            NULL if the file is not found or on memory allocation failure.
 */

char *_find_path(char *command)
{
	char *path = getenv("PATH");
	char *folder = strtok(path, ":");
	char *abs_path = NULL;
	struct stat file_data;
	size_t command_len = _strlen(command);
	size_t folder_len, path_len;

	path_len = command_len + 2;

	abs_path = malloc(path_len * sizeof(char));
	if (abs_path == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	while (folder != NULL)
	{
		folder_len = _strlen(folder);

		if (folder_len + command_len + 1 > path_len)
		{
			path_len = folder_len + command_len + 1;
			abs_path = realloc(abs_path, path_len * sizeof(char));
			if (abs_path == NULL)
			{
				perror("realloc");
				return (NULL);
			}
		}
		_strcpy(abs_path, folder);
		_strcat(abs_path, "/");
		_strcat(abs_path, command);

		if (stat(abs_path, &file_data) == 0 && S_ISREG(file_data.st_mode)
				&& (file_data.st_mode & S_IXUSR))
			return (abs_path);
		folder = strtok(NULL, ":");
	}
	free(abs_path);
	return (NULL);
}
