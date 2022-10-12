#include "sort.h"
#include <stdio.h>

/**
 * sort_and_find_pivot - find pivot of array part
 *
 * @array: array part
 * @size: size of array part
 * @true_array: really array
 * @true_size: really array size
 *
 * Return: return pivot position
 */

int sort_and_find_pivot(int *array, int size, int *true_array, int true_size)
{
	int pivot = size - 1, i = -1, j = 0, save;

	if (size == 1 || size == 0)
		return (-1);

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			if (i != j)
			{
				save = array[j];
				array[j] = array[i];
				array[i] = save;
				print_array(true_array, true_size);
			}
		}
	}

	i++;

	if (i != pivot)
	{
		save = array[i];
		array[i] = array[pivot];
		array[pivot] = save;
		print_array(true_array, true_size);
	}

	return (i);
}


/**
 * sort - sort array part
 *
 * @array: array part
 * @size: size of array part
 * @true_array: really array
 * @true_size: really array size
 */

void sort(int *array, size_t size, int *true_array, int true_size)
{
	int pivot;

	if (array == NULL || size == 0)
		return;

	pivot = sort_and_find_pivot(array, size, true_array, true_size);

	if (pivot != -1)
	{
		sort(array, pivot, true_array, true_size);
		sort(array + pivot + 1, size - pivot - 1, true_array, true_size);
	}

}

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	sort(array, size, array, size);
}
