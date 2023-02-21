#include "main.h"

/**
 * main - prints the alphabet, in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	char w;

	for(w = 'a'; w <= 'z'; w++)
	{
		_putchar(w);
	}

	_putchar ('\n');

	return (0);
}
