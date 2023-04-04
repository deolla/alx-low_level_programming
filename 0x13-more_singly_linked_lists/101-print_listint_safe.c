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
	const listint_t *m, *o;

	m = head;

	while (m != NULL)
	{
		printf("[%p] %d\n", (void *)m, m->n);
		count++;

		o = m;
		m = m->next;

		if (o <= m)
		{
			printf("-> [%p] %d\n", (void *)m, m->n);
			exit(98);
		}
	}
	if (o <= m)
	{
		return (count);
	}
}
