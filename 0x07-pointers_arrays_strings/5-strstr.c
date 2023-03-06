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
	char *p1, *p2;

	while (*haystack != '\0')
	{
		p1 = haystack;
		p2 = needle;

		while (*p1 != '\0' &&  *p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}

		if (!*p2)
			return (p2);

		haystack = p1 + 1;
	}
	return (0);
}
