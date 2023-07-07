#include "hash_tables.h"

/**
 * hash_table_set - A function that adds an element to the hash table.
 * @ht: The hash table you want to add or update the key/value.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_hash_node;

	if (ht == NULL || key == NULL)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	new_hash_node = malloc(sizeof(hash_node_t));
	if (new_hash_node == NULL)
	{
		return (0);
	}
	new_hash_node->key = strdup(key);
	new_hash_node->value = strdup(value);
	new_hash_node->next = ht->array[index];

	ht->array[index] = new_hash_node;

	return (1);
}
