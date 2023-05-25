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
	ssize_t read;
	char *token;

	while (1)
	{
		if (display_command)
			_print_prompt();
		read = getline(&command, &command_size, stdin);

		if (read == -1)
		{
			if (feof(stdin))
				break;
			perror("getline");
			exit(1);
		}
		command[strcspn(command, "\n")] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			break;
		}
		token = strtok(command, "\n");
		while (token != NULL)
		{
			args[0] = command;
			args[1] = NULL;

			_process_command(command, args, &exit_status);
			token = strtok(NULL, "\n");
		}
	}
	free(command);
	return (exit_status);
}
