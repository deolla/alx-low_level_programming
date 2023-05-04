#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: points to a string.
 *
 * Return: converted number, or 0.
 */
unsigned int binary_to_uint(const char *b)
{
	int oo = 1;
	unsigned int mm = 0;

	if (b == NULL)
		return (0);

	for (oo = 0; b[oo] != '\0'; oo++)
	{
		if (b[oo] != '0' && b[oo] != '1')
		{
			return (0);
		}
		mm <<= 1;
		if (b[oo] == '1')
		{
			mm |= 1;
		}
	}
	return (mm);
}
