#include "main.h"

/**
 * int flip_bits - number of bits you would need to flip.
 * @n: unsigned long int.
 * @m: unsigned long int.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int kkk = 0;
	unsigned long int rrr = n ^ m;
	int lep;

	for (lep = 0; lep < (int)(sizeof(unsigned long int) * 8); lep++)
	{
		kkk += (rrr >> lep) & 1;
	}

	return (kkk);
}
