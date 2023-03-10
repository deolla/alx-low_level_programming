#include "stdio.h"
/**
 * main - a program that prints the number of arguments passed into it
 * @argc: int argument
 * @argv: char pointer argument.
 *
 * Description: prints the number of arguments passed into it.
 * Return: always 0.
 */
int main(int argc, char *argv[0])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
