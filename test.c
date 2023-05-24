#include "shell.h"


#define COMMAND_BUFFER_SIZE 1000

/**
 * _process_command- Function that processes a user command.
 * handles quotes, comments, built-in commands, and executes external commands.
 *
 * @command: The user command to process.
 * @args: An array of strings to store the parsed command arguments.
 * @exit_status: A pointer to the exit status variable to be updated.
 */
void _process_command(char *command, char *args[], int *exit_status)
{
	    char *command_copy = _process_command_copy(command);
	        if (command_copy == NULL)
			     {
				             return;
					          }

		    _parse_command(command_copy, args);

		        if (args[0] == NULL) {
				        free(command_copy);
					        return;
						    }

			    if (_strcmp(args[0], "exit") == 0) {
				            free(command_copy); 
					            exit(*exit_status);
						            return;
							        }

			        if (_strcmp(args[0], "env") == 0) {
					        _env_builtin();
						        free(command_copy); 
							        return;
								    }

				    _handle_builtin_commands(args, exit_status);

				        free(command_copy);
}

char *_process_command_copy(const char *command)
{
	    
	    char *command_copy = strdup(command);
	        return command_copy;
		free(command_copy);
}

void _parse_command(char* command_copy, char *args[])
{
	    char* index = NULL;
	        int z, quote_flag = 0;
		    char last_char = '\0';
		        char* ptr;

			    for (ptr = command_copy; *ptr != '\0'; ++ptr) {
				            if (*ptr == '"' && last_char != '\\')
						                quote_flag = !quote_flag;
					            else if (*ptr == '#' && !quote_flag && last_char != '\\') {
							                index = ptr;
									            break;
										            }
						            last_char = *ptr;
							        }

			        if (index != NULL)
					        *index = '\0';

				    command_copy[strcspn(command_copy, "\n")] = '\0';

				        for (z = 0; z < COMMAND_BUFFER_SIZE / 2 + 1; z++)
						        args[z] = NULL;

					    _parse_line(command_copy, args);
					    free(command_copy);
}


void _handle_builtin_commands(char *args[], int *exit_status)
{
	 int execution_status;
	    if (args[0] == NULL)
		            return;

	        if (_strcmp(args[0], "exit") == 0) {
			        exit(*exit_status);
				        return;
					    }

		    if (_strcmp(args[0], "env") == 0) {
			            _env_builtin();
				            return;
					        }

		        execution_status = _execute(args);
			    if (execution_status == -1) {

				        }

			        *exit_status = execution_status;
}
