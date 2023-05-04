#include "main.h"

/**
 * get_bit -  value of a bit at a given index.
 * @n: unsigned int.
 * @index: the index.
 *
 * Return: index or -1 if an error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int diff;

	if (index >= sizeof(unsigned int) * 8)
		return (-1);

	diff = 1UL << index;
	return ((n & diff) ? 1 : 0);
}
