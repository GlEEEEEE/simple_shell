#include "shell.h"

/**
* print_prompt - Print the shell prompt.
*/
void print_prompt(void)
{
write(STDOUT_FILENO, "($) ", 4);
}

