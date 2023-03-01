#include "main.h"

/**
 * reverse_array - a function that reverses
 * the content of an array of integers.
 * @a: an integer
 * @n: the number of elements of the array.
 */
void reverse_array(int *a, int n)
{
	int m, o, tmp;

	m = 0;
	o = n - 1;

	while (m < o)
	{
		tmp = a[m];
		a[m] = a[o];
		a[o] = tmp;

		m++;
		o--;
	}
}
