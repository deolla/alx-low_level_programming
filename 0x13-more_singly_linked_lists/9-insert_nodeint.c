#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: double pointer.
 * @idx: index of the list.
 * @n: int variable
 * Return: new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *wee;
	unsigned int l;

	if (*head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0 || *head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	wee = *head;
	for (l = 0; l < idx - 1 && wee->next != NULL; l++)
	{
		wee = wee->next;
	}
	if (l < idx - 1)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = wee->next;
	wee->next = new_node;
	return (new_node);
}
