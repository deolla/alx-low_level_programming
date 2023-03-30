#include "lists.h"

/**
 * add_node_end - adds a new node at the end.
 * @head: beginning of the linked list.
 * @str: pointer string.
 *
 * Description: a function that adds a new node at the end.
 * Return: address of the new element, or NULL if failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	int newlem = 0;
	list_t *newnode;
	list_t *end = *head;

	newnode = malloc(sizeof(list_t));

	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->str = strdup(str);

	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = newnode;
	}
	while (str[newlem])
	{
		newlem++;
	}
	newnode->len = newlem;

	return (newnode);
}
