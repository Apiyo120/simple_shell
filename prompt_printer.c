#include "shell.h"

/**
 * _print_prompt- Prints the shell prompt.
 */
void _print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
