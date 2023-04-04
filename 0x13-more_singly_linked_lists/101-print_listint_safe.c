#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: double pointer.
 *
 * Return: number of nodes.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *os, *ot;

	os = head;
	ot = head;

	while (os != NULL && os->next != NULL)
	{
		printf("[%p] %d\n", (void *)ot, ot->n);
		count++;
		ot = ot->next;
		os = os->next->next;

		if (ot == os)
		{
			printf("[%p] %d\n", (void *)ot, ot->n);
			count++;
			break;
		}
	}
	if (os == NULL || os->next == NULL)
	{
		while (ot != NULL)
		{
			printf("[%p] %d\n", (void *)ot, ot->n);
			count++;
			ot = ot->next;
		}
	}
	else
	{
		printf("-> [%p] %d\n", (void *)ot, ot->n);
		count++;
	}
	if (count == 0)
	{
		printf("NULL\n");
	}
	return (count);
}
