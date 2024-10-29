#include "sort.h"

/**
 * swap_nodes - function to swap nodes
 * @list: list
 * @node_a: node a
 * @node_b: node b
 */

void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	listint_t *prev_a, *next_a, *prev_b, *next_b;

	if (node_a == node_b)
		return;

	prev_a = node_a->prev;
	next_a = node_a->next;
	prev_b = node_b->prev;
	next_b = node_b->next;

	/* Adjust links for node_a */
	if (prev_a)
		prev_a->next = node_b;
	if (next_a)
		next_a->prev = node_b;

	/* Adjust links for node_b */
	if (prev_b)
		prev_b->next = node_a;
	if (next_b)
		next_b->prev = node_a;

	/* Swap the next and prev pointers */
	node_b->prev = prev_a;
	node_b->next = next_a;
	node_a->prev = prev_b;
	node_a->next = next_b;

	/* Update the head of the list if necessary */
	if (*list == node_a)
		*list = node_b;
	else if (*list == node_b)
		*list = node_a;

	/* Print the list after swapping */
}
/**
 * cocktail_sort_list - cocktail sort function
 * @list: list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start;
	listint_t *end = NULL;

	if (!list || !(*list))
		return;

	do {
		swapped = 0;
		start = *list;

		for (; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
		}
		end = start;

		if (swapped)
		{
			swapped = 0;
			for (; start->prev != NULL; start = start->prev)
			{
				if (start->n < start->prev->n)
				{
					swap_nodes(list, start->prev, start);
					swapped = 1;
				}
			}
		}
	} while (swapped);

	print_list(*list);
}

