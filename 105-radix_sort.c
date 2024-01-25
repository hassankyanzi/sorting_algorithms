#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * getMax - Get the maximum value in the array
 * @array: The array to find the maximum value in
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * countSort - Sort the array using counting sort based on a significant digit
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The significant digit to consider
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sort an array of integers using the LSD Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
	{
		return;
	}

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
	}
}

