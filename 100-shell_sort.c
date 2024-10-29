#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t j, i, interval;

	if (!array || size < 2)
		return;

	for (interval = size / 2; interval > 0; interval /= 2)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;

		}
		print_array(array, size);
	}
}

