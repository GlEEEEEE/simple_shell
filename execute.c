#include "shell.h"

/**
* execute - execute a command using execvp.
*
* @args: array of arguments.
*
* Return: On success, returns 0. On failure, returns 1.
*/
int execute(char **args)
{
pid_t pid;
int status;

if (check_builtin(args))
return (0);

pid = fork();
if (pid == -1)
{
perror("execute: fork");
return (1);
}

if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execute: execvp");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}

return (0);
}

