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
	char **words = NULL;
	char *arg, **new_words;
	size_t size = 0;
	int z = 0;

	arg = strtok(line, separator);
	while (arg)
	{
		if ((size_t)z >= size)
		{
			size = size + 20;
			new_words = _realloc(words, size * sizeof(char *),
					(size + 20) * sizeof(char *));
			if (!new_words)
			{
				_free_args(words);
				return (NULL);
			}
			words = new_words;
		}
		words[z] = strdup(arg);
		if (!words[z])
		{
			_free_args(words);
			return (NULL);
		}
		z++;

		arg = strtok(NULL, separator);
	}
	words = _realloc(words, (z + 1) * sizeof(char *),
			(z + 1) * sizeof(char *));
	if (!words)
	{
		_free_args(words);
		return (NULL);
	}
	words[z] = NULL;
	return (words);
}
