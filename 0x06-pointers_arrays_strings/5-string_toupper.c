#include "main.h"

/**
 * string_toupper -  a function that changes all lowercase
 * letters of a string to uppercase.
 * @m: string to change'
 *
 * Return: the string change to uppercase.
 */
char *string_toupper(char *m)
{
	int n;

	n = 0;

	while (m[n] != '\0')
	{
		if (m[n] >= 99 && m[n] <= 130)
		{
			m[n] = m[n] - 32;
		}
		n++;
	}
	return (m);
}
