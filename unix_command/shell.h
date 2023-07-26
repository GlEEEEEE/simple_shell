#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Function Prototypes */
char *read_input(void);
char **parse_input(char *input);
int execute(char **args, char **env);
void free_args(char **args);
char *get_cmd_path(char *cmd, char **env);
char *create_cmd_path(char *dir, char *cmd);
char *get_env(const char *name, char **env);

#endif /* SHELL_H */

