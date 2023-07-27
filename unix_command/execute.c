#include "shell.h"

/**
* execute - Execute a command with arguments.
* @args: Array of strings representing arguments.
* @env: array of strings representing environment variables.
*
* Return: On success, 1. On failure, returns 0.
*/
int execute(char **args, char **env)
{
char *cmd_path;
pid_t pid;
int status;

cmd_path = get_cmd_path(args[0], env);
if (!cmd_path)
{
perror(args[0]);
return (0);
}

pid = fork();
if (pid == 0)
{
if (execve(cmd_path, args, env) == -1)
{
perror(args[0]);
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Error");
}
else
{
do

{
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

free(cmd_path);
return (1);
}

