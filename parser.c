#include "shell.h"

/**
 * _parse_line - parse a line into arguments
 * @line: the line to parse
 *
 * Return: array of arguments
 */

char **_parse_line(char *line)
{
	const char *separator = " \t\n";
	char **words, *arg;
	size_t size = 0;
	int z = 0;

	words = malloc(sizeof(char *));
	if (!words)
		return (NULL);

	arg = strtok(line, separator);
	while (arg)
	{
		if ((size_t)z == size)
		{
			size = size + 20;
			words = _realloc(words, size * sizeof(char *),
					(size + 20) * sizeof(char *));
			if (!words)
				return (NULL);
		}

		words[z] = arg;
		z++;

		arg = strtok(NULL, separator);
	}
	words[z] = NULL;
	return (words);
}
