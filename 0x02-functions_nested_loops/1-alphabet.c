#include "main.h"

/**
 * main -  start of function
 *
 * Description: prints the alphabet, in lowercase, followed by a new line.
 * Return: Always 0 (Success)
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
