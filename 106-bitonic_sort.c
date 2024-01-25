#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - compare and swap if needed
 * @array: array to compare
 * @size: size of array
 * @i: index i
 * @j: index j
 * @dir: direction
 */
void bitonic_compare(int *array, size_t size, size_t i, size_t j, int dir)
{
	if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
	{
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
		print_array(array, size);
	}
}

/**
 * bitonic_merge - recursively merge and sort the array
 * @array: array to sort
 * @size: size of array
 * @dir: direction
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t k, half;

	if (size > 1)
	{
		half = size / 2;

		for (k = 0; k < half; k++)
			bitonic_compare(array, size, k, k + half, dir);

		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
}

/**
 * bitonic_sort_recursive - recursively sort the array
 * @array: array to sort
 * @size: size of array
 * @dir: direction
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
	size_t half;

	if (size > 1)
	{
		half = size / 2;
		bitonic_sort_recursive(array, half, 1);
		bitonic_sort_recursive(array + half, half, 0);
		bitonic_merge(array, size, dir);
	}
}

/**
 * bitonic_sort - sort an array using Bitonic sort
 * @array: array to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}

