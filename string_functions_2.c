#include "shell.h"

/**
 * _getenv - function that retrieves the value of an environment variable
 * specified by the given name.
 * @name: name of the environment variable to retrieve.
 *
 * Return: pointer to the value of the environment variable
 * otherwise NULL.
 */

char *_getenv(const char *name)
{
	int name_len, z;

	if	(name == NULL || environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	for	(z = 0; environ[z] != NULL; z++)
	{
		if	(_strncmp(environ[z], name, name_len) == 0 && environ[z][name_len] == '=')
			return (environ[z] + name_len + 1);
	}
	return (NULL);
}
