#include "sort.h"

/**
 * quick_sort_and_partition - partitioning and sorting
 *
 * @array: Array to be sorted
 * @low: starting index
 * @high: ending index
 *
 * Return: start
 */
int quick_sort_and_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int a, temp;
	int i = (low - 1);

	for (a = low; a <= high - 1; a++)
	{
		/* current element is smaller than the pivot*/
		if (array[a] < pivot)
		{
			/* Increment index of smaller element*/
			i++;
			/*swap(&array[i], &array[a]);*/
			if (i != a)
			{
				temp = array[i];
				array[i] = array[a];
				array[a] = temp;
				print_array(array, high + 1);
			}
		}
	}
	if (low != high && array[low] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		/*swap(&array[i + 1], &array[high]);*/
		print_array(array, high + 1);
	}
	return (i + 1);
}
/**
 * quickSortRecursive - recursive
 *
 * @array: Array to be sorted
 * @low: starting index
 * @high: ending index
 *
 * Return: start
 */
void quickSortRecursive(int *array, int low, int high)
{
	int p;

	if (low < high)
	{
		p = quick_sort_and_partition(array, low, high);
		quickSortRecursive(array, low, p - 1);
		quickSortRecursive(array, p + 1, high);

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
	if (size < 2)
		return;
	quickSortRecursive(array, 0, size - 1);
}
