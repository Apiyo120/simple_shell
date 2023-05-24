#include "shell.h"

/**
 * _parse_line - Parses input line and separates to individual arguments.
 *
 * @line: The input to be parsed.
 * @args: An array of strings to store the parsed arguments.
 */

void _parse_line(char *line, char **args)
{
	int z = 0;
	char *end;
	bool has_arguments = true;

	while (isspace(*line))
		line++;

	if (*line == '\0')
	{
		args[0] = NULL;
		return;
	}
	while (*line != '\0')
	{
		end = strchr(line, ' ');

		if (end == NULL)
		{
			args[z++] = line;
			break;
		}
		end = '\0';

		args[z++] = line;
		line = end + 1;

		while (isspace(*line))
			line++;
		has_arguments = false;
	}

	args[z] = NULL;

	if (has_arguments && _strcmp(args[0], "exit") == 0)
		_exit_builtin();
}
