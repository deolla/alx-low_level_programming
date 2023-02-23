#include "main.h"

/**
 * print_most_numbers -  prints the numbers, from 0 to 9,
 * followed by a new line.
 *
 * Return: Always 0
 */
void print_most_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i != 4 && i != 2)
		_putchar(i + '0');
	}
	_putchar('\n');
}
