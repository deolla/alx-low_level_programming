#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat -  concatenates two strings.
 * @s1: string.
 * @s2: string.
 * @n: bytes.
 *
 * Return: pointer.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0' && len2 < n)
	{
		len2++;
	}

	new_str = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		new_str[i] = s1[i];
	}

	for (j = 0; j < len2; j++)
	{
		new_str[i + j] = s2[j];
	}

	new_str[i + len2] = '\0';

	return (new_str);
}
