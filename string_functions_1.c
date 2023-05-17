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














