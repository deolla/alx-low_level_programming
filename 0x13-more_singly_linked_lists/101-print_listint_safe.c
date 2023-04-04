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
	const listint_t *me, *omo;

	if (!head)
		exit(98);

	me = head;

	while (me)
	{
		printf("[%p] %d\n", (void *)me, me->n);
		count++;
		omo = me;
		me = me->next;
		if (omo <= me)
		{
			printf("-> [%p] %d\n", (void *)me, me->n);
			exit(98);
		}
	}
	return (count);
}
