#include "custom_realloc.h"
#include <stdlib.h>
#include <stddef.h>

/**
* _realloc - Reallocates a block of memory.
* @ptr: Pointer to the previously allocated memory block.
* @old_size: Old size of the memory block in bytes.
* @new_size: New size of the memory block in bytes.
*
* Return: returns pointer to the realloc memory block or Null.
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
void *new_ptr;
size_t i;

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

for (i = 0; i < old_size && i < new_size; i++)
((char *)new_ptr)[i] = ((char *)ptr)[i];

free(ptr);
return (new_ptr);
}
