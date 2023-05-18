#include "shell.h"

/**
 * _strdup - duplicates a string.
 * @str:strings to duplicate.
 *
 * Return: pointer to duplicate string, NULL if malloc fails.
 */

char *_strdup(char *str)
{
	char *dup;
	int len = 0;

	if (!str)
		return (NULL);
	while (str[len])
	{
		len++;
	}
	dup = malloc(sizeof(char) * (len + 1));

	if (!dup)
		return (NULL);
	len = 0;

	while (str[len])
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}


/**
 * _strcat - concatenates two strings.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: Pointer to concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len, z;

	if (dest == NULL || src == NULL)
		return (NULL);

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;

	for (z = 0; src[z] != '\0'; z++)
		dest[dest_len + z] = src[z];

	dest[dest_len + z] = '\0';
	return (dest);
}

/**
 * _strlen - calculates the length of a string.
 * @str: string to calculate the length of.
 *
 * Return: length of the string.
 */

int _strlen(char *str)
{
	int len = 0;

	while	(str[len])
		len++;
	return (len);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * @env: array of environment variables
 *
 * Return: value of the environment variable or NULL if not found
 */
char *_getenv(const char *name, char **env)
{
	int y, z, len;
	char *env_var;

	if (!name || !env)
		return (NULL);

	len = strlen(name);
	for (y = 0; env[y] != NULL; y++)
	{
		env_var = env[y];
		for (z = 0; z < len; z++)
		{
			if (name[z] != env_var[z])
				break;
		}
		if (z == len && env_var[z] == '=')
		{
			return (env_var + z + 1);
		}
	}
	return (NULL);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 and s2 are equal, otherwise difference
 */
int _strcmp(char *s1, char *s2)
{
	int z = 0;

	while (s1[z] && s2[z])
	{
		if (s1[z] != s2[z])
			return (s1[z] - s2[z]);
		z++;
	}
	return (s1[z] - s2[z]);
}
