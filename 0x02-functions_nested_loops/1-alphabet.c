#include "main.h"

/**
 * print_alphabet - function to print abc
 *
 * Return: Always 0
 */
void print_alphabet(void)
{
	char q = 'a';

	while (q <= 'z')
	{

		_putchar(q);
		q++;

	}
	_putchar('\n');
}
