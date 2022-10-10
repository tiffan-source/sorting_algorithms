#include "sort.h"

/**
 * selection_sort - sorts an array of
 * integers in ascending order using
 * the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size to sort
 */

void selection_sort(int *array, size_t size)
{
	int i, j, save, index_swap;

	for (i = 0; i < (int)size; i++)
	{
		index_swap = i;

		for (j = i + 1; j < (int)size; j++)
		{
			if (array[index_swap] > array[j])
			{
				index_swap = j;
			}
		}

		if (index_swap != i)
		{
			save = array[i];
			array[i] = array[index_swap];
			array[index_swap] = save;
			print_array(array, size);
		}
	}
}
