#include "hash_tables.h"

/**
 * hash_djb2 - A hash function implementing the djb2 algorithm.
 * @str: the string.
 *
 * Return: The result.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;

	hash = 5381;
	for (; *str != '\0'; str++)
	{
		hash = ((hash << 5) + hash) + (unsigned long)(*str);
	}

	return (hash);
}
