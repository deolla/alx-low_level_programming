#include "lists.h"

/**
 * *add_nodeint_end - adds a new node at the
 * end of a listint_t list
 * @head: pointer pointing to the next node.
 * @n: integer to be added to new node.
 *
 * Description: a function that adds a new node
 * at the end of a listint_t list.
 * Return: No return.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp = *head;
	int h;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		for (h = 0; temp->next != NULL; temp = temp->next, h++)
			;
	}
	temp->next = new_node;

	return (new_node);

}
