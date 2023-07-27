#include "shell.h"

/**
* get_cmd_path - Get the full path of a command.
*
* create_cmd_path: full command path of token dir.
*
* @cmd: The command name to search for.
* @dir: The array of environment variables.
*
*
* Return: Pointer to dyn alloc string or Null
*/
char *create_cmd_path(char *dir, char *cmd)
{
char *cmd_path;
size_t dir_len, cmd_len, path_len;

if (!dir || !cmd)
return (NULL);

dir_len = strlen(dir);
cmd_len = strlen(cmd);
path_len = dir_len + cmd_len + 2; /* +2 for '/' and '\0'*/

cmd_path = malloc(path_len);
if (!cmd_path)
return (NULL);

strcpy(cmd_path, dir);
strcat(cmd_path, "/");
strcat(cmd_path, cmd);

return (cmd_path);
}

char *get_cmd_path(char *cmd, char **env)
{
char *path, *token, *cmd_path;
char *token_dir;
char *delim = ":";
int access_status;

path = get_env("PATH", env);
if (!path)
return (NULL);

token = strtok(path, delim);
while (token != NULL)
{
token_dir = strdup(token);
if (!token_dir)
return (NULL);

cmd_path = create_cmd_path(token_dir, cmd);
free(token_dir);
if (!cmd_path)
return (NULL);

access_status = access(cmd_path, X_OK);
if (access_status == 0)
return (cmd_path);

free(cmd_path);
token = strtok(NULL, delim);
}

return (NULL);
}

