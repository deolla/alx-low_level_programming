#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of hash table.
 *
 * Return: pointer to the newly created hash table or NULL if error.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: Hash table.
 * @key: The key to insert
 * @value: The value associated with key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_hash_node, *tmp;
	char *cpy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	cpy = strdup(value);
	if (cpy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = cpy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new_hash_node = malloc(sizeof(shash_node_t));
	if (new_hash_node == NULL)
	{
		free(cpy);
		return (0);
	}
	new_hash_node->key = strdup(key);
	if (new_hash_node->key == NULL)
	{
		free(cpy);
		free(new_hash_node);
		return (0);
	}
	new_hash_node->value = cpy;
	new_hash_node->next = ht->array[index];
	ht->array[index] = new_hash_node;

	if (ht->shead == NULL)
	{
		new_hash_node->sprev = NULL;
		new_hash_node->snext = NULL;
		ht->shead = new_hash_node;
		ht->stail = new_hash_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_hash_node->sprev = NULL;
		new_hash_node->snext = ht->shead;
		ht->shead->sprev = new_hash_node;
		ht->shead = new_hash_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new_hash_node->sprev = tmp;
		new_hash_node->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new_hash_node;
		else
			tmp->snext->sprev = new_hash_node;
		tmp->snext = new_hash_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key.
 * @ht: Hash table.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if key not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *hash_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	hash_node = ht->shead;
	while (hash_node != NULL && strcmp(hash_node->key, key) != 0)
		hash_node = hash_node->snext;

	return ((hash_node == NULL) ? NULL : hash_node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: hash table.
 *
 * Return: no return.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *hash_node;

	if (ht == NULL)
		return;

	hash_node = ht->shead;
	printf("{");
	while (hash_node != NULL)
	{
		printf("'%s': '%s'", hash_node->key, hash_node->value);
		hash_node = hash_node->snext;
		if (hash_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: hash table.
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *hash_node;

	if (ht == NULL)
		return;

	hash_node = ht->stail;
	printf("{");
	while (hash_node != NULL)
	{
		printf("'%s': '%s'", hash_node->key, hash_node->value);
		hash_node = hash_node->sprev;
		if (hash_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *pop = ht;
	shash_node_t *hash_node, *tmp;

	if (ht == NULL)
		return;

	hash_node = ht->shead;
	while (hash_node)
	{
		tmp = hash_node->snext;
		free(hash_node->key);
		free(hash_node->value);
		free(hash_node);
		hash_node = tmp;
	}

	free(pop->array);
	free(pop);
}
