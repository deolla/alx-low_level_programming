#include "main.h"
#include <stdio.h>

/**
 * main - a program that prints the minimum number of
 * coins to make change for an amount of money.
 * @argc: int argument
 * @argv: char pointer argument.
 *
 * Description: prints the minimum number of
 * coins to make change for an amount of money.
 * Return: always 0 or 1.
 */
int main(int argc, char **argv)
{
	long int sum, coin = 0;
	int cent[5] = {25, 10, 5, 2, 1};

	int u;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}

	sum = atoi(argv[1]);

	if (sum < 0)
	{
		puts("Error");
		return (1);
	}

	for (u = 0; u < 5; u++)
	{
		while (sum - cent[u] >= 0)
		{
			coin++;
			sum -= cent[u];
		}
	}

	printf("%li\n", coin);

	return (0);
}

/**
 * atoi - converts a string argument to an interger.
 * @s: pointer string.
 *
 * Return: string.
 */
long int atoi(char *s)
{
	unsigned int fud;
	int fod;

	fud = 0;
	fod = 1;

	for (; *s; s++)
	{
		if (*s >= '0' && *s <= '9')
		{
			fud *= 10;
			fud += *s - '0';
		}
		else if (fud > 0)
		{
			break;
		}
		else if (*s == '-')
		{
			fod = -fod;
		}
	}

	return (fud * fod);
}
