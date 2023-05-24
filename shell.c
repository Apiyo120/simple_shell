#include "shell.h"

/**
 * main - function that runs the interactive shell.
 *
 * Return: The exit status of the shell.
 */

#define COMMAND_BUFFER_SIZE 1000

int main(void)
{
	char command[COMMAND_BUFFER_SIZE];
	char *args[COMMAND_BUFFER_SIZE / 2 + 1];
	int exit_status = 0;

	while (1)
	{
		_print_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			break;
		}

		_process_command(command, args, &exit_status);
	}
	return (exit_status);
}
