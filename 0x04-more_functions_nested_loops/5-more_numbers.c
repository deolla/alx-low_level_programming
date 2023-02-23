#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14,
 * followed by a new line'
 *
 * Return: Always 0
 */
void more_numbers(void)
{
	int n, m;

	for (n = 0; n <= 9; n++)
	{
		for (m = 0; m < 14; m++)
		{
			if (m >= 10)
			{
				_putchar((m / 10) + '0');
			}
			_putchar((m % 10) + '0');
		}
		_putchar('\n');
	}
}
