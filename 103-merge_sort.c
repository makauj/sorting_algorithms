#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into one sorted array.
 *
 * @array: The original array.
 * @left: The starting index of the left sub-array.
 * @mid: The ending index of the left sub-array.
 * @right: The ending index of the right sub-array.
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t left_size = mid - left + 1;
	size_t right_size = right - mid;

	int *left_array = malloc(left_size * sizeof(int));
	int *right_array = malloc(right_size * sizeof(int));

	if (!left_array || !right_array)
		return;

	for (i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < right_size; j++)
		right_array[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}

	free(left_array);
	free(right_array);

	print_array(array, right - left + 1);
}

/**
 * merge_sort_recursive - Helper function to perform merge sort.
 *
 * @array: The array to be sorted.
 * @left: The starting index of the array segment to sort.
 * @right: The ending index of the array segment to sort.
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}

