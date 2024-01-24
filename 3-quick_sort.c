#include "sort.h"

/**
 * partition - partitions the array and returns the pivot index
 * @array: the array to be partitioned
 * @low: the lowest bond of the array
 * @high: the highest bond of the array
 * @size: the size of the array
 *
 * Return: the index of the pivot element after partitioning (i + 1)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - recursively sorts the array using
 * the Quick sort algorithm
 * @array: the array to be partitioned
 * @low: the lowest bond of the array
 * @high: the highest bond of the array
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be partitioned
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
