#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned int m;

	hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}
	hash_table->size = size;
	for (m = 0; m < size; m++)
		hash_table->array[m] = NULL;

	return (hash_table);
}
