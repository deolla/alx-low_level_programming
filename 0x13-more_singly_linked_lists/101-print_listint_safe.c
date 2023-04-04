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
	const listint_t *me;

	while (head != NULL)
	{
		printf("[%p] %d\n", head, head->n);
		count++;
		me = head;
		head = head->next;

		if (me <= head)
		{
			printf("-> [%p] %d\n", head, head->n);
			exit(98);
		}
	}
	return (count);
}
