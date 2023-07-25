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
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a;
	int temp;
	int i = low - 1;

	for (a = low; a <= high - 1; a++)
	{
		/* current element is smaller than the pivot*/
		if (array[a] <= pivot)
		{
			/* Increment index of smaller element*/
			i++;
			/*swap(&array[i], &array[a]);*/
			if (i != a)
			{
				temp = array[i];
				array[i] = array[a];
				array[a] = temp;
				print_array(array, size);
			}
		}
	}
	/*swap(&array[i + 1], &array[high]);*/
        if (low != high && array[low] != array[high])
        {
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quickSortRecursive - recursive
 *
 * @array: Array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: Size of the array
 *
 * Return: start
 */
void quickSortRecursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quickSortRecursive(array, low, p - 1, size);
		quickSortRecursive(array, p + 1, high, size);

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
	if (array == NULL || size < 2)
		return;

	quickSortRecursive(array, 0, size - 1, size);
}
