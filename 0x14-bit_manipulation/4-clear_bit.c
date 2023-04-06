#include "main.h"

/**
 * clear_bit -  sets the value of a bit.
 * @n: unsigned long int.
 * @index: index.
 *
 * Return: 1 or or -1 if an error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ddd;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	ddd = ~(1UL << index);
	*n &= ddd;

	return (1);
}
