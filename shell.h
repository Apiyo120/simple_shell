#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;
char **_copy_env(void);
char **_parse_line(char *line);
int _is_builtin(char **args);
int _execute_builtin(char **args, char **env);
char *_find_path(char *command, char **env);
int _execute(char **args, char *path, char **env);
int _print_error(char *command, char *message, int status);
void _free_args(char **args);
void _free_path(char *path);
void _free_env(char **env);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name, char **env);
int _strcmp(char *s1, char *s2);
void _print_env(char **env);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif 
