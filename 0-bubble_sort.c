#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, swap = 0, save;

	if (array == NULL)
		return;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				save = array[j];
				array[j] = array[j + 1];
				array[j + 1] = save;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
		swap = 0;
	}

}
