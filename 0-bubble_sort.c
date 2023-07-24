#include "sort.h"

/**
 * bubble_sort - Sorting an array of integers using BUBBLE SORT
 *
 * @array: Array to be usorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;
	int swapped;

	if (size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		swapped = 1;
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				swapped = 0;
				print_array(array, size);
			}
		}
		if (swapped == 1)
		break;
	}
}
