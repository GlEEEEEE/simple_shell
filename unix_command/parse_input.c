#include "shell.h"

/**
* parse_input - Tokenize the input string into arguments.
*
* @input: The input string to be tokenized.
*
* Return: An array of pointers to each argument or NULL on failure.
*/
char **parse_input(char *input)
{
char **args = NULL;
char *token;
int bufsize = 64;
int position = 0;

args = malloc(bufsize * sizeof(char *));
if (args == NULL)
{
perror("parse_input: malloc");
exit(EXIT_FAILURE);
}

token = strtok(input, " \t\n");
while (token != NULL)
{
args[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
args = realloc(args, bufsize *sizeof(char *));
if (args == NULL)
{
perror("parse_input: realloc");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n");
}

args[position] = NULL;
return (args);
}

