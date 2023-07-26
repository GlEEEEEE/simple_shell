#include "shell.h"

/**
* execute - Execute a command using execve.
*
* @args: The array of arguments.
* @env: environment variables.
*
* Return: On success, returns 0. On failure, returns 1.
*/
int execute(char **args, char **env)
{
pid_t pid;
int status;
char *cmd_path;


cmd_path = get_cmd_path(args[0], env);
if (cmd_path == NULL)
{
write(STDERR_FILENO, args[0], strlen(args[0]));
write(STDERR_FILENO, ": not found\n", 12);
return (1);
}

pid = fork();
if (pid == -1)
{
perror("execute: fork");
free(cmd_path);
return (1);
}

if (pid == 0)
{

if (execve(cmd_path, args, NULL) == -1)
{
perror("execute: execve");
free(cmd_path);
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}

free(cmd_path);
return (0);
}

