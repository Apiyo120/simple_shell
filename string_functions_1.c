#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the new memory block
 *
 * Return: Pointer to the new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *p;
	unsigned int z;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		new_size = old_size;
	p = ptr;
	for (z = 0; z < new_size; z++)
		new_ptr[z] = p[z];

	free(ptr);

	return (new_ptr);
}

/**
 * _atoi - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: The converted integer value
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			break;
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sign);
}

/**
 * _print_env - Prints the environment
 * @env: The environment
 *
 * Return: Nothing
 */
void _print_env(char **env)
{
	unsigned int z;

	for (z = 0; env[z] != NULL; z++)
		write(STDOUT_FILENO, env[z], _strlen(env[z])), write(STDOUT_FILENO, "\n", 1);
}

/**
 * _copy_env - create a copy of the environment variables
 *
 * Return: pointer to the copy of environment variables
 */
char **_copy_env(void)
{
	int z, len;
	char **env_copy, **new_env;

	for (len = 0; environ[len]; len++)
	;

	env_copy = malloc((len + 1) * sizeof(char *));
	if (!env_copy)
		return (NULL);

	for (z = 0; z < len; z++)
		env_copy[z] = _strdup(environ[z]);

	env_copy[z] = NULL;
	new_env = _realloc(env_copy, (len + 1) * sizeof(char *),
				(len + 2) * sizeof(char *));
	if (!new_env)
	{
		_free_env(env_copy);
		return (NULL);
	}
	new_env[len + 1] = NULL;
	_free_env(env_copy);
	return (new_env);
}

