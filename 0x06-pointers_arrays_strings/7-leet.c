#include "main.h"

/**
 * leet - a function that encodes a string into 1337.
 * @q: the string encoded.
 *
 * Return: the encoded string.
 */
char *leet(char *q)
{
	int x, y;
	char v[] = "aAeEoOtTlL";
	char m[] = "4433007711";

	x = 0;
	while (q[x] != '\0')
	{
		y = 0;
		while (v[y] != '\0')
		{
			if (q[x] == v[y])
			{
				q[x] = m[y];
			}
			y++;
		}
		x++;
	}
	return (q);
}
