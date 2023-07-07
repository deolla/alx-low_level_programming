#include "hash_tables.h"

/**
 * hash_table_delete - A function that deletes a hash table.
 * @ht: hash table.
 *
 * Return: no return.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int m;
	hash_node_t *hash_node, *tmp;

	if (ht == NULL)
	{
		return;
	}

	for (m = 0; m < ht->size; m++)
	{
		hash_node = ht->array[m];
		while (hash_node != NULL)
		{
			tmp = hash_node->next;
			free(hash_node->key);
			free(hash_node->value);
			free(hash_node);
			hash_node = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
