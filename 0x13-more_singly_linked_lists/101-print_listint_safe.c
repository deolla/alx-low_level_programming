#include "lists.h"
size_t lop_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * lop_listint_len - prints a listint_t linked list.
 * @head: double pointer.
 *
 * Return: number of nodes.
 */
size_t lop_listint_len(const listint_t *head)
{
	size_t count = 1;
	const listint_t *help, *pls;

	if (head == NULL || head->next == NULL)
		return (0);

	help = head->next;
	pls = (head->next)->next;
	while (pls)
	{
		if (help == pls)
		{
			help = pls;
			while(help != pls)
			{
				count++;
				help = help->next;
				pls = pls->next;
			}
			help = help->next;
			while(help != pls)
			{
				count++;
				help = help->next;
			}
			return(count);
		}
		help = help-> next;
		pls = (pls->next)->next;
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
	size_t count, ind = 0;

	count = lop_listint_len(head);
	if(count == 0)
	{
		for (; head != NULL; count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for(ind = 0; ind < count; ind++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("->[%p] %d\n", (void *)head, head->n);
	}

	return (count);
}
