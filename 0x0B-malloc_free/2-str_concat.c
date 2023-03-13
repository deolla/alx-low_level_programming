#include "main.h"
#include <stdlib.h>

/**
 * *str_concat -  concatenates two strings.
 * @s1: string.
 * @s2: string.
 *
 * Description: a function that concatenates two strings.
 * Return: NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *strg;
	unsigned int m, n, o, len;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	for (m = 0; s1[m] != '\0'; m++)
		;
	for (n = 0; s2[n] != '\0'; n++)
		;

	strg = (char *)malloc(sizeof(char) * (m + n + 1));

	if (strg == NULL)
	{
		free(strg);
		return (NULL);
	}

	for (o = 0; o < m; o++)
		strg[o] = s1[o];

	len = n;
	for (n = 0; n <= len; n++)
		strg[o] = s2[n];

	return (strg);
}
