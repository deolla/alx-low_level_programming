#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 * @n: value
 *
 * Return: Always 0
 */
void print_diagonal(int n)
{
	int count;

	for (count = 0; count < n; count++)
	{
		_putchar('\');
	}
	_putchar('\n');
}
