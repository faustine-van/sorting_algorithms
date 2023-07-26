#include "sort.h"

/**
 * shell_sort - Sorting an array of integers using shell SORT alogorithm
 * using the Knuth sequence
 *
 * @array: Array to be usorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t a, b;
	size_t j; /* to hold gap size*/
	int temp;

	if (size < 2)
		return;

	for (j = size / 2; j > 0; j /= 2)
	{
		for (a = j; a < size; a++)
		{
			temp = array[a];
			for (b = a; b >= j; b -= j)
			{
				if (temp < array[b - j])
					array[b] = array[b - j];
				else
					break;
			}
			array[b] = temp;
		}
		print_array(array, size);
	}
}
