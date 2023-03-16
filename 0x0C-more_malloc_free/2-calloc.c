#include "main.h"
#include <stdlib.h>

/**
 * _calloc -  allocates memory for an array.
 * @nmemb: int array.
 * @size: size of array.
 *
 * Return: pointer.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *p;
	unsigned int total_size, i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	total_size = nmemb * size;

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	p = ptr;
	for (i = 0; i < total_size; i++)
	{
		p[i] = 0;
	}

	return (ptr);
}
