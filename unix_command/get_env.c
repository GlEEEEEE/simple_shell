#include "shell.h"

/**
* get_env - Get the value of an environment variable.
*
* @name: The name of the environment variable to retrieve.
* @env: The array of environment variables (char **) to search in.
*
* Return: a pointer or NULL if not found.
*/
char *get_env(char *name, char **env)
{
int i, len;
char *env_name, *value;

len = strlen(name);
for (i = 0; env[i]; i++)
{
env_name = env[i];
if (strncmp(env_name, name, len) == 0 && env_name[len] == '=')
{
value = env_name + len + 1;
return (value);
}
}

return (NULL);
}


