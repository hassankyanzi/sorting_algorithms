#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursive function for Quick sort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);

		/* Recursively sort the elements before and after the partition */
		recursive_quick_sort(array, low, partition_index - 1, size);
		recursive_quick_sort(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Swap array[i] and array[j] */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}

	/* Swap array[i + 1] and array[high] (pivot) */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after each swap */
	print_array(array, size);

	return (i + 1);
}

