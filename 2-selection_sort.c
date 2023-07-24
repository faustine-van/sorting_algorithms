#include "sort.h"

/**
 * selection_sort - Sorting an array of integers using SELECTION SORT
 *
 * @array: Array to be usorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t min;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;

		}

		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
