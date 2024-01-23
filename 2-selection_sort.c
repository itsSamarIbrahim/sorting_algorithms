#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, min_idx, temp;

	for (a = 0; a < size - 1; a++)
	{
		min_idx = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_idx])
				min_idx = b;
		}
		if (min_idx != a)
		{
			temp = array[a];
			array[a] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
