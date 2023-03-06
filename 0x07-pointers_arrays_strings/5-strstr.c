#include "main.h"

/**
 * _strstr - a function that locates a substring.
 * @haystack: string
 * @needle: substring
 *
 * Return: a pointer to the beginning of the located substring.
 */
char *_strstr(char *haystack, char *needle)
{
	char *p1, *p2, *p3;

	if (!*needle)
		return (haystack);

	while (*haystack)
	{
		p1 = haystack;
		p2 = needle;

		while (*p1 && *p2 && (*p1 == *p2))
		{
			p1++;
			p2++;
		}

		if (!*p2)
			return (haystack);

		p3 = haystack;
		haystack++;
	}

	return ('\0');
}
