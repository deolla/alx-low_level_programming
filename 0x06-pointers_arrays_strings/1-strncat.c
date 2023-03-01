#include "main.h"
#include <string.h>

/**
 * _strncat - a function that concatenates two strings.
 * @dest: destination.
 * @src: source.
 * @n: number of character to concentracte.
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	size_t dest_len = strlen(dest);
	int m;

	for (m = 0; m < n && src[m] != '\0'; m++)
	{
		dest[dest_len + m] = src[m];
	}

	dest[dest_len + m] = '\0';

	return (dest);
}
