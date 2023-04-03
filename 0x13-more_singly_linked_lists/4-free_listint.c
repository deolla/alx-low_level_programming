#include "lists.h"

/**
 * free_listint -  frees a listint_t list.
 * @head: a pointer pointing to node.
 *
 * Return: no return.
 */
void free_listint(listint_t *head)
{
	listint_t *tem;
	int k;

	for (k = 0; head != NULL; k++)
	{
		tem = head;
		head = head->next;
		free(tem);
	}
}
