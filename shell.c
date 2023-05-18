#include "shell.h"

/**
 * main - Entry point for simple shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *buffer = NULL, **args = NULL, *path = NULL, **env = NULL;
	ssize_t bytes_read = 0;
	size_t buffer_size = 0;
	int status = 0;

	env = _copy_env();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&buffer, &buffer_size, stdin);
		if (bytes_read == -1)
		{
			free(buffer);
			break;
		}
		args = _parse_line(buffer);
		if (!args)
		{
			free(buffer);
			continue;
		}
		if (_is_builtin(args))
		{
			status = _execute_builtin(args, env);
			_free_args(args);
			continue;
		}
		path = _find_path(args[0], env);
		if (path)
		{
			status = _execute(args, path, env);
			_free_path(path);
		}
		else
			status = _print_error(args[0], "not found", status);
		_free_args(args);
	}
	free(buffer);
	_free_env(env);
	write(STDOUT_FILENO, "\n", 1);
	return (status);
}
