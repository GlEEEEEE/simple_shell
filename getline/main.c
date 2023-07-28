#include <stdio.h>
#include "custom_realloc.h"
#include "custom_mgetline.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t characters;

printf("$ ");
while ((characters = mgetline(&line, &bufsize, stdin)) != -1)
{
printf("You typed: %s\n", line);
free(line);
line = NULL;
bufsize = 0;
printf("$ ");
}

return (0);
}

