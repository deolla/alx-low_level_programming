#include "main.h"
#include <stdio.h>

/**
 * infinite_add - function with 4 arguments
 * @n1: number
 * @n2: number
 * @r: buffer that the function will use to store the result
 * @size_r: the buffer size
 *
 * Return: r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int u0 = 0, u1 = 0, ops, ops1, dir0, dir1, ups = 0;

	while (*(n1 + u0) != '\0')
		u0++;
	while (*(n2 + u1) != '\0')
		u1++;
	if (u0 >= u1)
		ops1 = u0;
	else
		ops1 = u1;
	if (size_r <= ops1 + 1)
		return (0);
	r[ops1 + 1] = '\0';
	u0--, u1--, size_r--;
	dir0 = *(n1 + u0) - 48, dir0 = *(n2 + u1) - 48;
	while (ops1 >= 0)
	{
		ops = dir0 + dir1 + ups;
		if (ops >= 10)
			ups = ops / 10;
		else
			ups = 0;
		if (ops > 0)
			*(r + ops1) = (ops % 10) + 48;
		else
			*(r + ops1) = '0';
		if (u0 > 0)
			u0--, dir0 = *(n1 + u0) - 48;
		else
			dir0 = 0;
		if (u1 > 0)
			u1--, dir1 = *(n2 + u1) - 48;
		else
			dir1 = 0;
		ops1--, size_r--;
	}
	if (*(r) == '0')
		return (r + 1);
	else
		return (r);
}
