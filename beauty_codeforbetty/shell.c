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

signal(SIGINT, SIG_IGN);

while (1)
{
print_prompt();
input = read_input();
args = parse_input(input);

if (args != NULL)
{
status = execute(args);
free_args(args);
}

free(input);

if (status == 2)
break;
}

return (0);
}

