#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a program that adds positive numbers.
 * @argc: int argument
 * @argv: char pointer argument.
 *
 * Description: adds positive numbers.
 * Return: 0 or 1.
 */
int main(int argc, char *argv[])
{
	int m, n, result;

	result = 0;

	for (m = 1; m < argc; m++)
	{
		for (n = 0; argv[m][n] != '\0'; n++)
		{
			if (argv[m][n] < 47 || argv[m][n] > 57)
			{
				printf("Error\n");
				return (1);
			}
		}
		result = result + atoi(argv[m]);
	}
	printf("%d\n", result);

	return (0);
}
