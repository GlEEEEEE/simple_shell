#include "shell.h"

/**
* free_args - Free the memory allocated for the arguments.
*
* @args: The array of arguments to free.
*/
void free_args(char **args)
{
if (args == NULL)
return;

free(args);
}

