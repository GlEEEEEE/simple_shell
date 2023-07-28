#ifndef CUSTOM_MGETLINE_H
#define CUSTOM_MGETLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 1024

ssize_t mgetline(char **lineptr, size_t *n, FILE *stream);

#endif /* CUSTOM_MGETLINE_H */

