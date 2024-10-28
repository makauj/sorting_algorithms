#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @array: The array containing the integers
 * @a: The index of the first integer
 * @b: The index of the second integer
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 *
 * @arr: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array (for printing)
 *
 * Return: The final index of the pivot
 */
int lomuto_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high]; /* Choose the last element as pivot */
	int i = low - 1; /* Index of smaller element */
	int j = low;

	for (; j < high; j++)
	{
		/* If current element is smaller than pivot */
		if (arr[j] < pivot)
		{
			i++;
			swap(arr, i, j); /* Swap elements */
			/* Print the array after each swap */
			print_array(arr, size);
		}
	}
	/* Swap the pivot element to its correct position */
	swap(arr, i + 1, high);
	/* Print after pivot swap */
	print_array(arr, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array
 *
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		/* Partitioning index */
		pivot = lomuto_partition(array, low, high, size);
		/* Recursively sort elements before partition */
		quick_sort_recursive(array, low, pivot - 1, size);
		/* Recursively sort elements after partition */
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
