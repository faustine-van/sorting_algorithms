#include "sort.h"
/**
 * lomuto_partition - lomuto partition scheme for quick sort
 *
 * @array: Array to be partition
 * @low: starting index partition
 * @high: ending index partition
 * @size: Size of the array
 *
 * Return: Partition index
 */
void lomuto_partition(int *array, int low, int high, size_t size)
{
	int a, temp, h, w;

	if (low < high)
	{
		h = high;
		w = low;
		for (a = low; a < high; a++)
		{
			/* current element is smaller than the pivot*/
			if (array[a] < array[h])
			{
				/* Increment index of smaller element*/
				if (a != w)
				{
					temp = array[a];
					array[a] = array[w];
					array[w] = temp;
					print_array(array, size);
				}
				w++;
			}
		}
		/*swap(&array[i + 1], &array[high]);*/
		if (w != h && array[w] != array[h])
		{
			temp = array[w];
			array[w] = array[h];
			array[h] = temp;
			print_array(array, size);
		}
		lomuto_partition(array, low, w - 1, size);
		lomuto_partition(array, w + 1, high, size);

	}
}
/**
 * quick_sort - Sorting an array of integers using QUICK SORT
 *
 * @array: Array to be usorted
 * @size: Size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto_partition(array, 0, size - 1, size);
}

