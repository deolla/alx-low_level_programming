#include "main.h"

/**
 * set_bit - sets the value of a bit.
 * @n: unsigned long int.
 * @index: the index.
 *
 * Return: 1 or -1 if an error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int pop;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	pop = 1UL << index;
	*n |= pop;
	return (1);
}
