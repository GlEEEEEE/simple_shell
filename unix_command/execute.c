#include "shell.h"

/**
* execute - Execute a command using execve.
*
* @args: The array of arguments.
*
* Return: On success, returns 0. On failure, returns 1.
*/
int execute(char **args)
{
pid_t pid;
int status;
char *cmd_path;

pid = fork();
if (pid == -1)
{
perror("execute: fork");
return (1);
}

if (pid == 0)
{
cmd_path = args[0];

if (execve(cmd_path, args, NULL) == -1)
{
perror("execute: execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}

return (0);
}

