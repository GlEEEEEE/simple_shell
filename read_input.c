#include "shell.h"

/**
* read_input - Read a line of input from the user.
*
* Return: The input string or NULL on failure.
*/
char *read_input(void)
{
char *input = NULL;
size_t bufsize = 0;

if (getline(&input, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
write(STDOUT_FILENO, "\n", 1);
free(input);
exit(2);
}
else
{
perror("read_input: getline");
free(input);
exit(EXIT_FAILURE);
}
}

return (input);
}

