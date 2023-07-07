#include "hash_tables.h"

/**
 * hash_table_print - A function that prints a hash table.
 * @ht: hash table.
 *
 * Return: no return.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int m;
	int pop = 1;
	hash_node_t *hash_node;

	if (ht == NULL)
		return;

	printf("{");
	for (m = 0; m < ht->size; m++)
	{
		hash_node = ht->array[m];
		while (hash_node != NULL)
		{
			if (!pop)
				printf(", ");
			printf("'%s': '%s'", hash_node->key, hash_node->value);
			pop = 0;
			hash_node = hash_node->next;
		}
	}
	printf("}\n");
}
