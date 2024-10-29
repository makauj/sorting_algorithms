#include "sort.h"

/**
 * sift_down - function to maintain heap property
 *
 * @array: array
 * @size: size of the array
 * @index: index of the current element to be sifted down
 * @end: last index of the heap
 */

void sift_down(int *array, size_t size, size_t index, size_t end)
{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * indext + 2;
	int temp;

	if (left <= end && array[left] > array[largest])
		largest = left;
	if (right <= end && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		sift_down(array, size, largest, end);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	ssize_t end, i;
	int temp;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (end = size - 1; end > 0; end--)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;

		print_array(array, size);

		sift_down(array, size, 0, end - 1);
	}
}
