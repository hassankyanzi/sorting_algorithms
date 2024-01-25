#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme
 * @array: array to partition
 * @size: size of the array
 * @low: lower bound
 * @high: higher bound
 * Return: partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - recursive function to implement Quick Sort
 * @array: array to sort
 * @size: size of the array
 * @low: lower bound
 * @high: higher bound
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = hoare_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, partition_index);
		quick_sort_recursive(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

