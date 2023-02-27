#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: The string
 *
 * Return: no return
 */
void rev_string(char *s)
{
	int n, rev, rev1;
	char str;

	rev = 0;
	rev1 = 0;

	while (s[rev] != '\0')
	{
		rev++;
	}
	rev1 = rev - 1;

	for (n = 0; n < rev / 2; n++)
	{
		str = s[n];
		s[n] = s[rev1];
		s[rev1--] = str;
	}

}
