#include "sort.h"

/**
 * bubble_sort - Bubble sort Algorithm
 * @array - array to be sorted
 * @size - size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;

	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; i < size - step - 1; ++i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
