#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - prints a listint_t linked list.
 * @head: double pointer.
 *
 * Return: 0.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tor, *h;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	tor = head->next;
	h = (head->next)->next;
	while (h)
	{
		if (tor == h)
		{
			tor = head;
			while (tor != h)
			{
				nodes++;
				tor = tor->next;
				h = h->next;
			}
			tor = tor->next;
			while (tor != h)
			{
				nodes++;
				tor = tor->next;
			}
			return (nodes);
		}
		tor = tor->next;
		h = (h->next)->next;
	}
	return (0);
}


/**
 * print_listint_safe - print listint_t list.
 * @head: pointer.
 *
 * Return: numbers of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, f;

	nodes = looped_listint_len(head);
	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (f = 0; f < nodes; f++)
		{
			printf("[%p]%d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("->[%p]%d\n", (void *)head, head->n);
	}
	return (nodes);
}
