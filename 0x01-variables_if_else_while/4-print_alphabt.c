#include <stdio.h>

/**
 * main -  prints the alphabet in lowercase, followed by a new line.
 * Print all the letters except q and e
 * No Description
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase;

	for(lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		if (lowercase != 'e' && lowercase != 'q')
			putchar(lowercase);
	}

	putchar('\n');

	return (0);
}
