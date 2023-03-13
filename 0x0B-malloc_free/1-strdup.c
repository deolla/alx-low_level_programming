#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * @str: string.
 *
 * Description: a function that returns a pointer to
 * a newly allocated space in memory.
 * Return: NULL if str = NULL, else a pointer.
 */
char *_strdup(char *str)
{
	unsigned int n, m;
	char *dup_str;

	if (str == NULL)
	{
		return (NULL);
	}

	for (n = 0; str[n] != '\0'; n++)
		;
	dup_str = (char *)malloc(sizeof(char) * (n + 1));

	if (dup_str == NULL)
	{
		return (NULL);
	}

	for (m = 0; m <= n; m++)
		dup_str[m] = str[n];

	return (dup_str);
}
