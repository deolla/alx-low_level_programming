#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked -  allocates memory.
 * @b: variable
 *
 * Return: pointer or cause normal process termination.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}

	return (ptr);
}
