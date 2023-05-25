#include "shell.h"

#define PATH_MAX 1024

void update_pwd(char *dir);

/**
 * _cd - function that changes the current working directory of the process.
 * @args: array of strings representing the command arguments.
 */

void _cd(char **args)
{
	char *dir = args[1];

	if	(dir == NULL || _strcmp(dir, "i") == 0)
		dir = _getenv("HOME");
	if	(dir == NULL)
	{
		char error_hme[] = "Error: Home directory not found. \n";

		write(STDERR_FILENO, error_hme, sizeof(error_hme) - 1);

		return;
	}

	if	(_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if	(dir == NULL)
		{
			char err_pwd[] = "Error: Previous working directory not found. \n";

			write(STDERR_FILENO, err_pwd, sizeof(err_pwd) - 1);

			return;
		}
		write(STDOUT_FILENO, dir, _strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
	}
	if	(chdir(dir) != 0)
	{
		char cd_err[] = "Error: Failed to change directory. \n";

		write(STDERR_FILENO, cd_err, sizeof(cd_err) - 1);

		return;
	}
	update_pwd(dir);
}

/**
 * update_pwd - function updates the value of the PWD environment variable
 * @dir: the directory path to update the PWD environment variable with.
 */

void update_pwd(char *dir)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		_setenv("PWD", cwd, 1);
		_setenv("OLDPWD", dir, 1);
	}
}
