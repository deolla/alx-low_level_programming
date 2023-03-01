#include "main.h"

/**
 * cap_string - a function that capitalizes
 * all words of a string.
 * @n: the string to be capitalised
 *
 * Return: capitalised string
 */
char *cap_string(char *n)
{
	int a, c;
	char cap[13] = {' ', '\t', '\n', ',', ';', '.', '!',
		'?', '"', '(', ')', '{', '}'};

	for (a = 0; n[a] != '\0'; a++)
	{
		if (a == 0 && n[a] >= 'a' && n[a] <= 'z')
			n[a] -= 32;

		for (c = 0; c < 13; c++)
		{
			if (n[a] == cap[c])
			{
				if (n[a + 1] >= 'a' && n[a + 1] <= 'z')
				{
					n[a + 1] -= 32;
				}
			}
		}
	}
	return (n);
}
