#include "main.h"

/**
 * infinite_add - function with 4 arguments
 * @n1: char type pointer argument
 * @n2: char type pointer argument
 * @r: char type pointer argument
 * @size_r: int type argument
 *
 * Return: sum of two integers
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int count, count1;

	while (n1[count] != '\0')
		count++;
	while (n2[count1] != '\0')
		count1++;

	*r = *(r + size_r);
	while (n1[count] > 0 || n1[count1] > 0)
	{
		if (n1[count] + n2[count1] > 0)
			*r = n1[count - 1] + n2[count1 - 1] + 1;
		else
			*r = n1[count] + n2[count1];
		count--;
		count1--;
	}
	return (r);
}
