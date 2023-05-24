#include "shell.h"

#define COMMAND_BUFFER_SIZE 1000

/**
 * _process_command- Function that processes a user command.
 * handles quotes, comments, built-in commands, and executes external commands.
 *
 * @command: The user command to process.
 * @args: An array of strings to store the parsed command arguments.
 */
void _process_command(char *command, char *args[])
{
	char *index = NULL;
	int z, quote_flag = 0;
	char last_char = '\0';
	char *ptr;

	for (ptr = command; *ptr != '\0'; ++ptr)
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

	command[strcspn(command, "\n")] = '\0';

	for (z = 0; z < COMMAND_BUFFER_SIZE / 2 + 1; z++)
		args[z] = NULL;

	_parse_line(command, args);

	if (args[0] == NULL)
		return;
	if (_strcmp(args[0], "exit") == 0)
	{
		free(command);
		_exit_builtin();
		return;
	}
	if (_strcmp(args[0], "env") == 0)
	{
		_env_builtin();
		return;
	}
	_execute(args);
}
