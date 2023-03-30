#include <stdio.h>

void print(void) __attribute__((constructor));

/**
 * print - prints.
 *
 * Return: void.
 */
void print(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
