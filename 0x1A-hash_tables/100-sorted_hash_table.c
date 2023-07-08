#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table
 *
 * Return: pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int m;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (m = 0; m < size; m++)
		ht->array[m] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table
 * @ht: The hash table
 * @key: The key to insert
 * @value: The value associated with the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_hash_node, *current_hash_node, *prev_hash_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current_hash_node = ht->array[index];
	prev_hash_node = NULL;

	while (current_hash_node != NULL)
	{
		if (strcmp(current_hash_node->key, key) == 0)
		{
			free(current_hash_node->value);
			current_hash_node->value = strdup(value);
			if (current_hash_node->value == NULL)
				return (0);
			return (1);
		}
		if (strcmp(current_hash_node->key, key) > 0)
			break;

		prev_hash_node = current_hash_node;
		current_hash_node = current_hash_node->next;
	}
	new_hash_node = malloc(sizeof(shash_node_t));
	if (new_hash_node == NULL)
		return (0);

	new_hash_node->key = strdup(key);
	new_hash_node->value = strdup(value);
	if (new_hash_node->key == NULL || new_hash_node->value == NULL)
	{
		free(new_hash_node->key);
		free(new_hash_node->value);
		free(new_hash_node);
		return (0);
	}
	new_hash_node->next = current_hash_node;
	if (prev_hash_node != NULL)
		prev_hash_node->next = new_hash_node;
	else
		ht->array[index] = new_hash_node;

	if (ht->shead == NULL || strcmp(new_hash_node->key, ht->shead->key) < 0)
	{
		new_hash_node->sprev = NULL;
		new_hash_node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new_hash_node;
		ht->shead = new_hash_node;
		if (ht->stail == NULL)
			ht->stail = new_hash_node;
	}
	else if (strcmp(new_hash_node->key, ht->stail->key) > 0)
	{
		new_hash_node->sprev = ht->stail;
		new_hash_node->snext = NULL;
		ht->stail->snext = new_hash_node;
		ht->stail = new_hash_node;
	}
	else
	{
		shash_node_t *tmp = ht->shead->snext;

		while (tmp != NULL && strcmp(new_hash_node->key, tmp->key) > 0)
			tmp = tmp->snext;

		new_hash_node->sprev = tmp->sprev;
		new_hash_node->snext = tmp;
		tmp->sprev->snext = new_hash_node;
		tmp->sprev = new_hash_node;
	}
	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key.
 * @ht: The hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *hash_node;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	hash_node = ht->array[index];

	while (hash_node != NULL)
	{
		if (strcmp(hash_node->key, key) == 0)
			return (hash_node->value);
		hash_node = hash_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in ascending order
 * @ht: The hash table.
 *
 * Return: no return.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *hash_node;
	int pop = 1;

	if (ht == NULL)
		return;

	printf("{");
	hash_node = ht->shead;

	while (hash_node != NULL)
	{
		if (pop)
			pop = 0;
		else
			printf(", ");
		printf("'%s': '%s'", hash_node->key, hash_node->value);
		hash_node = hash_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in descending order
 * @ht: The hash table.
 *
 * Return: no return.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *hash_node;
	int pop = 1;

	if (ht == NULL)
		return;

	printf("{");
	hash_node = ht->stail;

	while (hash_node != NULL)
	{
		if (pop)
			pop = 0;
		else
			printf(", ");
		printf("'%s': '%s'", hash_node->key, hash_node->value);
		hash_node = hash_node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table
 *
 * Return: no return.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *hash_node, *tmp;
	unsigned long int m;

	if (ht == NULL)
		return;

	for (m = 0; m < ht->size; m++)
	{
		hash_node = ht->array[m];
		while (hash_node != NULL)
		{
			tmp = hash_node;
			hash_node = hash_node->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
