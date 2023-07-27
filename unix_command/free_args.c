#include "shell.h"

/**
* free_args - Frees memory alloc for an array
*
* @args: array of strings are to be freed.
*
* Return: void.
*/
void free_args(char **args)
{
int i = 0;
while (args[i])
{
free(args[i]);
i++;
}
free(args);
}
