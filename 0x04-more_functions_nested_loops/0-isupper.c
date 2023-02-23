#include "main.h"

/**
 * _isupper - check for uppercase character.
 * @c: the character to be checked
 * Return: 1 if c is uppercase, 0 otherwise
 */

int _isupper(int c)
{
	char upper;

	for (upper = 'A'; upper <= 'Z'; upper++)
	{
		if (c == upper)
			return (1);
	}

	return (0);
}
