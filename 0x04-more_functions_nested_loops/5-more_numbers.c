#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14,
 * followed by a new line'
 *
 * Return: Always 0
 */
void more_numbers(void)
{
i	int n, m;

	for (n = 0; n < 10; n++)
	{
		for (m = 0; m < 1; m++)
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
