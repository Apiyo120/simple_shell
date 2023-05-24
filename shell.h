#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>


extern char **environ;

void _exit_builtin(void);
void _parse_line(char *line, char **args);
void _env_builtin(void);
int _execute(char **args);
char *_find_path(char *command);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, const char *src);
void process_command(char *command, char *args[], int *exit_status);
void _print_prompt(void);
char *_process_command_copy(const char* command);
void _parse_command(char* command_copy, char* args[]);
void _handle_builtin_commands(char* args[], int* exit_status);
int _execute_command(char* args[]);
void _process_command(char* command, char* args[], int* exit_status);

#endif
