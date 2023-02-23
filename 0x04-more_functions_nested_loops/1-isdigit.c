#include "main.h"

/**
 * _isdigit -  checks for a digit.
 * @c: input value to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	char num;

	for (num >= 0; num <= 10; num++)
	{
		if (c == num)
			return (1);
	}

	return (0);
}
