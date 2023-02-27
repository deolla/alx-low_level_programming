#include "main.h"

/**
 * print_rev - prints a string, in reverse.
 * @s: the string to print.
 *
 * Return: print string.
 */
void print_rev(char *s)
{
	int rev = 0;

	while (s[rev] != '\0')
	{
		_putchar(s[rev]);
		rev++;
	}
	_putchar('\n');
}
