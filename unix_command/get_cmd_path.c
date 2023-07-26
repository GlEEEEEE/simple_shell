#include "shell.h"

/**
* get_cmd_path - get the full path of the command.
*
* @cmd: The cmd to find the full path of.
* @env: environment variables.
*
* Return: full path of the cmd or NULL if not found.
*/
char *get_cmd_path(char *cmd, char **env)
{
char *path, *token, *tmp;
char *cmd_path = NULL;
struct stat st;
int found = 0;

path = get_env("PATH", env);

if (path != NULL)
{
tmp = strdup(path);
token = strtok(tmp, ":");
while (token != NULL)
{
cmd_path = create_cmd_path(token, cmd);
if (cmd_path != NULL)
{
if (stat(cmd_path, &st) == 0)
{
found = 1;
break;
}
free(cmd_path);
}
token = strtok(NULL, ":");
}
free(tmp);
free(path);
}

if (found == 0)
return (NULL);

return (cmd_path);
}

/**
* create_cmd_path - Create a full command path
* @dir: The directory containing the command
* @cmd: The command to concatenate with the directory
*
* Return: The full command path, or NULL on failure
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
