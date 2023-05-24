#include "shell.h"

/**
 * main - function that runs the interactive shell.
 *
 * Return: The exit status of the shell.
 */

#define COMMAND_BUFFER_SIZE 1000

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[COMMAND_BUFFER_SIZE / 2 + 1];
	int display_command = isatty(STDIN_FILENO);
	int exit_status = 0;

	while (1)
	{
		if (display_command)
		{
			_print_prompt();
		}
		if (getline(&command, &command_size, stdin) == -1)
			break;
		_process_command(command, args, &exit_status);

		if (_strcmp(args[0], "exit") == 0)
		{
			_exit_builtin();
			break;
		}
	}
	free(command);
	return (exit_status);
}
