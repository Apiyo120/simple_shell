#include "shell.h"

/**
 * _print_error - prints error message to standard error
 * @command: name of command
 * @message: error message
 * @status: exit status
 *
 * Return: exit status
 */

int _print_error(char *command, char *message, int status)
{
	char *error_message = NULL;

	error_message = _strcat(command, ": ");
	error_message = _strcat(error_message, message);
	error_message = _strcat(error_message, "\n");

	write(STDERR_FILENO, error_message, _strlen(error_message));
		free(error_message);

	return (status);
}
