#include "sort.h"

/**
 * counting_sort - counting sort algorithm function
 * @array: aray
 * @size: size
 */

void counting_sort(int *array, size_t size)
{
	int max, *count;
	size_t i, index;

	if (!array || size <= 1)
		return;

	/* Find the max value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array */
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* initialize the counting array with 0 */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count occurences of each value in the input array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	for (i = 0; i <= max; i++)
	{
		printf("%d ", count[i]);
	}
	printf("\n");

	/* Sort the original array using the counting array */
	index = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index++] = i;
			count[i]--;
		}
	}
	free(count); /* free allocated memory */
}
