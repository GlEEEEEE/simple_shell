#include "shell.h"

/**
* get_env - Get the value of an environment variable.
*
* @name: The name of the environment variable.
* @env: The environment variables.
*
* Return: The value of the environment variable or NULL if not found.
*/
char *get_env(const char *name, char **env)
{
char *value, *var;
int i;

for (i = 0; env[i] != NULL; i++)
{
var = strtok(env[i], "=");
if (strcmp(var, name) == 0)
{
value = strtok(NULL, "=");
return (value);
}
}

return (NULL);
}

