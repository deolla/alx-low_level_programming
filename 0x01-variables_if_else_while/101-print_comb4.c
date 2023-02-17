#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all possible different combinations of three digits.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int p, o, m;

	for (p = 48; p < 58; p++)
	{
		for (o = 49; o < 58; o++)
		{
			for (m = 50; m < 58; m++)
			{
				if (m > o && o > p)
				{
					putchar(p);
					putchar(o);
					putchar(m);
					if (p != 55 || o != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
