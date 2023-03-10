#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main -  a program that multiplies two numbers.
 * @argc: int argument
 * @argv: char pointer argument.
 *
 * Description: multiplies two numbers.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	int m;

	if (argc == 3)
	{
		m = atoi(argv[1]) * atoi(argv[2]);
				printf("%d\n", m);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
