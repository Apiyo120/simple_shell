#include "shell.h"

#define COMMAND_BUFFER_SIZE 1024


/**
 * parseLine-Parses a command line string
 * and stores the individual arguments in an array.
 *
 * @command:The command line string to be parsed.
 * @args: An array to store the parsed arguments.
 */

void parseLine(char *command, char **args)
{
	int index = 0;
	char *token = strtok(command, " \t\n");

	while (token != NULL)
	{
		args[index++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[index] = NULL;
}

/**
 *  executeCommand- Executes a command by invoking
 *  the corresponding functionality
 *  based on the arguments.
 *
 * @command: The command to be executed.
 * @exit_status: A pointer to the exit status variable.
 *
 * Return: 1 if the command is an "exit" command, 0 otherwise.
 */

int executeCommand(char *command, int *exit_status)
{
	char *args[COMMAND_BUFFER_SIZE / 2 + 1];

	parseLine(command, args);

	if (args[0] == NULL)
		return (0);

	if (_strcmp(args[0], "exit") == 0)
	{
		free(command);
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		env_builtin();
		return (0);
	}
	*exit_status = _execute(args);
	return (0);
}

/**
 * readCommand- Reads a command line from the standard input.
 *
 * @command: A pointer to the command string.
 * @command_size: A pointer to the size of the command string.
 */

void readCommand(char **command, size_t *command_size)
{
	if (getline(command, command_size, stdin) == -1)
		*command = NULL;
}

/*
 * processCommand: A function that processes a command line
 * by removing comments and newline characters
 *
 */

void processCommand(char **command)
{
	char *index, last_char, *ptr;
	int quote_flag;

	quote_flag = 0;
	last_char = '\0';
	index = NULL;

	for (ptr = *command; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '"' && last_char != '\\')
			quote_flag = !quote_flag;
		else if (*ptr == '#' && !quote_flag && last_char != '\\')
		{
			index = ptr;
			break;
		}
		last_char = *ptr;
	}

	if (index != NULL)
		*index = '\0';

	(*command)[strcspn(*command, "\n")] = '\0';
}

/**
 * main - function that runs the interactive shell.
 *
 * Return: The exit status of the shell.
 */

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	int display_command = isatty(STDIN_FILENO);
	int exit_status = 0;

	while (1)
	{
		if (display_command)
			write(STDOUT_FILENO, "#James&Diana$ ", 14);

		readCommand(&command, &command_size);

		if (command == NULL)
			break;

		processCommand(&command);

		if (executeCommand(command, &exit_status))
			break;
	}
	free(command);
	return (exit_status);
}
