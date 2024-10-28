#include "sort.h"

/**
 * insertion_sort_list - simple sorting algorithm
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *next = NULL, *temp = NULL;

	if (!list || !*list || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		temp = current->prev;

		while (temp && temp->n > current->n)
		{
			swap_nodes(list, temp, current);
			print_list(*list);
			temp = current->prev;
		}
		current = next;
	}
}
