#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOKEN_BUFSIZE 64

char **parse_input(char *line);
char *get_env(char *name, char **env);
char *create_cmd_path(char *dir, char *cmd);
char *get_cmd_path(char *cmd, char **env);
int execute(char **args, char **env);
void free_args(char **args);

#endif /* SHELL_H */

