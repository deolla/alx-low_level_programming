#include <stdio.h>

/**
 * main - a program that prints the lowercase alphabet in reverse
 * No Description
 * Return 0 (Success)
 */
int main(void)
{
	char lowercase;

	for (lowercase = 'z'; lowercase >= 'a'; lowercase--)
		putchar(lowercase);

	putchar('\n');

	return (0);
}
