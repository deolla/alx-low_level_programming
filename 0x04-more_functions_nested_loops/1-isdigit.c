#include "main.h"

/**
 * _isdigit -  checks for a digit (0 through 9).
 * @c: input value to check
 * return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	int i;

	for(i >= 0; i <= 10; i++)
	{
		if (c == i)
			return (1);
	}

	return (0)
}
