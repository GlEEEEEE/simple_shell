#include "shell.h"

/**
* check_builtin - Check if the command is a built-in.
*
* @args: The array of arguments.
*
* Return: 1 if built-in, 0 else.
*/
int check_builtin(char **args)
{
if (args[0] == NULL)
return (0);

if (strcmp(args[0], "exit") == 0)
return (1);

/*  more built-in checks here */

return (0);
}

