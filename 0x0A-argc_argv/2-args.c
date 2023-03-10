#include "main.h"
#include <stdio.h>

/**
 * main -  a program that prints all arguments it receives.
 * @argc: int argument.
 * @argv: char pointer argument.
 *
 * Description: prints all arguments it receives.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	int a;

	for (a = 0; a < argc; a++)
	{
		printf("%s\n", argv[a]);
	}

	return (0);
}
