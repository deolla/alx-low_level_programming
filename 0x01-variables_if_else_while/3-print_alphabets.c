#include <stdio.h>

/**
 * main - Start of function
 * No Description
 * Return: Always 0 (Success)
 */
int main(void)
{
	char Letters;

	for (Letters = 'A'; Letters <= 'Z'; Letters++)
		putchar(Letters);
	
	for (Letters = 'a'; Letters <= 'z'; Letters++)
		putchar(Letters);

	putchar('\n');

	return(0);
}
