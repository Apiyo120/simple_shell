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
	ssize_t getline_result;

	while (1)
	{
		if (display_command)
		{
			_print_prompt();
		}
		getline_result = getline(&command, &command_size, stdin);

		if (getline_result == -1)
		{
			if (feof(stdin))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			break;
		}

		_process_command(command, args, &exit_status);
	}
	free(command);
	return (exit_status);
}
