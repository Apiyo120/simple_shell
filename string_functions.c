#include "shell.h"

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
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 and s2 are equal, otherwise difference
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcpy - copies a string including the null-terminating byte
 * @dest: destination buffer
 * @src: source string
 *
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	char *dest_start = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}


/**
 * _atoi - Convert string to integer using custom_atoi.
 * @str: The string to be converted to an integer.
 *
 * Return: The converted integer value.
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int z = 0;

	while (str[z] == ' ' || str[z] == '\t')
		z++;

	if (str[z] == '-')
	{
		sign = -1;
		z++;
	}
	else if (str[z] == '+')
	{
		z++;
	}

	while (str[z] >= '0' && str[z] <= '9')
	{
		result = result * 10 + (str[z] - '0');
		z++;
	}
	return (sign * result);
}
