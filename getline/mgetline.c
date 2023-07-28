#define READ_SIZE 1024

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
* mgetline - Read a line from standard input
* @lineptr: Double pointer to the buffer storing the line
* @n: Pointer to the size of the buffer
*
* Return: Number of characters read, or -1 on failure
*/
ssize_t mgetline(char **lineptr, size_t *n)
{
size_t i;

if (lineptr == NULL || n == NULL)
return (-1);

*n = READ_SIZE;
*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
return (-1);

while (1)
{
int c = getchar();
if (c == EOF || c == '\n')
{
(*lineptr)[i] = '\0';
break;
}

(*lineptr)[i] = c;
i++;

if (i >= *n)
{
*lineptr = realloc(*lineptr, *n + READ_SIZE);
if (*lineptr == NULL)
return (-1);
*n += READ_SIZE;
}
}

return (i);
}

