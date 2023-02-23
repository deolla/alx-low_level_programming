#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 * @n: value
 *
 * Return: Always 0
 */
void print_diagonal(int n)
{
	int a, b;

	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			_putchar(' ');
		}
		_putchar(92);
		if (a > (n - 1))
			_putchar('\n');
	}
	_putchar('\n');
}
