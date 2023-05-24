#include "shell.h"

/**
 * main - function that runs the interactive shell.
 *
 * Return: The exit status of the shell.
 */

#define COMMAND_BUFFER_SIZE 1000

int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[COMMAND_BUFFER_SIZE / 2 + 1];
	int display_command = isatty(STDIN_FILENO);
	int exit_status = 0;
	int z, len;

	if (argc > 1)
	{
		write(STDOUT_FILENO, "Command line arguments:\n",
				_strlen("Command line arguments:\n"));
		for (z = 1; z < argc; z++)
		{
			char arg_buffer[COMMAND_BUFFER_SIZE];

			len = snprintf(arg_buffer, COMMAND_BUFFER_SIZE,
					"Argument %d: %s\n", z, argv[z]);
			write(STDOUT_FILENO, arg_buffer, len);
		}
	}
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
