#include "shell.h"

/**
* create_cmd_path - Create the full path of the command.
*
* @dir: The directory from the PATH.
* @cmd: The command.
*
* Return: The full path of the command or NULL on failure.
*/
char *create_cmd_path(char *dir, char *cmd)
{
char *cmd_path;
size_t dir_len, cmd_len;
int total_len;

dir_len = strlen(dir);
cmd_len = strlen(cmd);
total_len = dir_len + cmd_len + 2;

cmd_path = malloc(total_len);
if (cmd_path == NULL)
{
perror("create_cmd_path: malloc");
return (NULL);
}

snprintf(cmd_path, total_len, "%s/%s", dir, cmd);
return (cmd_path);
}

