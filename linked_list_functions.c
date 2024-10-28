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
	print_list(*list);
}

/**
 * insertion_sort_list - Function to perform insertion sort on linked list
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !((*list)->next))
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *next = current->next;
		listint_t *temp = current->prev;

		while (temp && temp->n > current->n)
		{
			swap_nodes(list, temp, current);
			temp = current->prev; /* Move to the previous node */
		}
		current = next; /* Move to the next node */
	}
}
