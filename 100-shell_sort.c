#include "sort.h"

/**
 * pow_3 - get a 3 power
 *
 * @power: power to find
 * Return: 3^power
 */

long int pow_3(int power)
{
	if (power == 0)
		return (1);

	return (3 * pow_3(power - 1));
}

/**
 * get_gap - obtain gap ofvKnuth sequence
 *
 * @index_gap: index gap to find
 * Return: gap for index_gap
 */

long int get_gap(int index_gap)
{
	return ((pow_3(index_gap) - 1) / 2);
}

/**
 * sort_by_gap - sort array using a gap
 *
 * @array: array to sort
 * @size: array size
 * @index_gap: index of gap to use for sorting
 */

void sort_by_gap(int *array, int size, int index_gap)
{
	int i, save, j;
	long int gap = get_gap(index_gap);

	if (gap <= size)
		sort_by_gap(array, size, index_gap + 1);

	for (i = 0; (i < size) && (i + gap < size); i++)
	{
		if (array[i] > array[i + gap])
		{
			save = array[i];
			array[i] = array[i + gap];
			array[i + gap] = save;
		}

		j = i;

		while (j - gap >= 0 && array[j - gap] > array[j])
		{
			save = array[j];
			array[j] = array[j - gap];
			array[j - gap] = save;
			j = j - gap;
		}
	}

	if (gap <= size)
		print_array(array, size);
}

/**
 * shell_sort - sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 *
 * @array: array to sort
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		sort_by_gap(array, size, 1);
}
