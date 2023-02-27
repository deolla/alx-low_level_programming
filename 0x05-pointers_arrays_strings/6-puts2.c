#include "main.h"

/**
 * puts2 -  prints every other character of a string,
 * starting with the first character
 * @str: character of a string
 *
 * Return: null.
 */
void puts2(char *str)
{
	int cha, n;

	cha = 0;

	while (str[cha] != '\0')
	{
		cha++;
	}

	for (n = 0; n < cha; n++)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
}
