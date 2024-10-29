#include "deck.h"


/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * 
 * Return: the difference between s1 and s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * get_rank_index - Helper function to get rank index
 * @value: value
 *
 * Return: an index for each rank and suit
 */
int get_rank_index(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
		};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1); /* should never reach here if all values are valid */
}

/**
 * compare_nodes - Function to compare two nodes
 * @a: node a
 * @b: node b
 *
 * Return: the comparison
 */
int compare_nodes(deck_node_t *a, deck_node_t *b)
{
	int rankA = get_rank_index(a->card->value);
	int rankB = get_rank_index(b->card->value);

	/* Compare by rank first */
	if (rankA != rankB)
		return (rankA - rankB);

	/* If ranks are the same, compare by suit */
	return (a->card->kind - b->card->kind);
}

/**
 * swap_nodes - Swap two adjacent nodes (a and b) in the list
 * @deck: head pointer
 * @a: node a
 * @b: node b
 *
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;
}

/**
 * sort_deck - Sort deck using insertion sort
 * @deck: the deck
 *
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *sorted, *next;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	sorted = *deck;
	current = sorted->next;

	while (current)
	{
		next = current->next;

		while (current->prev && compare_nodes(current->prev, current) > 0)
		{
			swap_nodes(deck, current->prev, current);
		}

		current = next;
	}
}

