#include "shell.h"

/**
* main - Simple Shell Entry Point
*
* Return: Always 0.
*/
int main(void)
{
char *input;
char **args;
int status;
extern char **environ;

signal(SIGINT, SIG_IGN);

while (1)
{
write(STDOUT_FILENO, "($) ", 4);
input = read_input();
args = parse_input(input);

if (args != NULL)
{
status = execute(args, environ);
free_args(args);
}

free(input);

if (status == 2)
break;
}

return (0);
}

