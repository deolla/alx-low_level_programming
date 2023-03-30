#include "lists.h"

/**
 * add_node -  adds a new node at the beginning.
 * @head: begining of the linked list.
 * @str: string pointer.
 *
 * Description: a function that adds a new node at the beginning.
 * Return: new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	int newlem;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str  = strdup(str);

	for (newlem = 0; str[newlem]; newlem++)
		;
	new_node->len = newlem;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
