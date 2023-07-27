#include "shell.h"

/**
* main - Simple shell main function.
* @argc: The number of arguments (unused).
* @argv: The array of command-line arguments (unused).
* @env: The array of environment variables.
*
* Return: Always returns 0.
*
* __attribute__((unused)): prevents unused var warning.
*/
int main(int __attribute__((unused)) argc,
char __attribute__((unused)) **argv,
char **env)
{
char *line = NULL;
char **args;
size_t bufsize = 0;
ssize_t read_chars;

int status
while (1)
{
printf("($) ");
read_chars = getline(&line, &bufsize, stdin);
if (read_chars == -1)
{
if (isatty(STDIN_FILENO))
printf("\n");
break;
}

args = parse_input(line);
if (args == NULL)
{
perror("Error parsing input");
continue;
}

status = execute(args, env);

free_args(args);
}

free(line);
return (0);
}
