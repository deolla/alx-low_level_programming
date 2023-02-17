#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all possible combinations of two two-digit numbers.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int q, d;

	for (q = 0; q < 100; q++)
	{
		for (d = 0; d < 100; d++)
		{
			if (q < d)
			{
				putchar((q / 10) + 48);
				putchar((q % 10) + 48);
				putchar(' ');
				putchar((d / 10) + 48);
				putchar((d % 10) + 48);
				if (q != 98 || d != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
