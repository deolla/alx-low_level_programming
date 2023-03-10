#include "main.h"
#include <stdio.h>

/**
 * main - a program that prints the number of arguments passed into it.
 * @argc: int argument
 * @argv: char pointer argument.
 *
 * Description: prints the number of arguments passed into it.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	(void)argv;
	argc--;
	printf("%d\n", argc);
	return (0);
}
