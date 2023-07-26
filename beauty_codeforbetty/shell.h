#ifndef SHELL_H
#define SHELL_H

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* function Prototypes */
void print_prompt(void);
char **parse_input(char *input);
char *read_input(void);
int execute(char **args);
int check_builtin(char **args);
void free_args(char **args);

#endif /* SHELL_H */

