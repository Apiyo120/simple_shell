#include "shell.h"

int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _getenv - function that retrieves the value of an environment variable
 * specified by the given name.
 * @name: name of the environment variable to retrieve.
 *
 * Return: pointer to the value of the environment variable
 * otherwise NULL.
 */

char *_getenv(char *name)
{
	int z;
	size_t name_len;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	for	(z = 0; environ[z] != NULL; z++)
	{
		if (_strncmp(environ[z], name, name_len) == 0 && environ[z][name_len] == '=')
			return (environ[z] + name_len + 1);
	}
	return (NULL);
}



/**
 *  _strncmp - function compares the first n characters of two strings
 * @s1:string one
 * @s2:srtring two
 * @n: first character
 *
 * Return: a negative value if s1 is less than s2
 * a positive value if s1 is greater than s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t z;

	for (z = 0; z < n; z++)
	{
		if (s1[z] != s2[z])
			return (s1[z] - s2[z]);
		else if (s1[z] == '\0')
			return (0);
	}
	return (0);
}
