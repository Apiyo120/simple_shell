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
	size_t folder_len, command_len, path_len;

	while (folder != NULL)
	{
		folder_len = _strlen(folder);
		command_len = _strlen(command);
		path_len = folder_len + 1 + command_len + 1;

		abs_path = malloc(path_len * sizeof(char));
		if (abs_path == NULL)
		{
			return (NULL);
		}
		_strcpy(abs_path, folder);
		_strcat(abs_path, "/");
		_strcat(abs_path, command);

		if (stat(abs_path, &file_data) == 0 && S_ISREG(file_data.st_mode)
				&& (file_data.st_mode & S_IXUSR))
		{
			return (abs_path);
		}
		free(abs_path);
		folder = strtok(NULL, ":");
	}
	return (NULL);
}
