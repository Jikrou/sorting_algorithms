#include "sort.h"
/**
 * quick_sort - a function that sorts an array of integers in ascending order
 * @array: a pointer to the array to be sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 *lomuto_partition - Partitions the array using the Lomuto partition scheme
 *@array: Pointer to the array to be partitioned
 *@low: Index of the low end of the partition
 *@high: Index of the high end of the partition
 *@size: Size of the array
 *Return: Index of the pivot element after partitioning
*/
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 *swap - Swaps two integers in an array
 *@a: Pointer to the first integer
 *@b: Pointer to the second integer
*/

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *quicksort_recursive - Recursively sorts the array using Quick sort
 *@array: Pointer to the array to be sorted
 *@low: Index of the low end of the partition
 *@high: Index of the high end of the partition
 *@size: Size of the array
*/
void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
	size_t pi = lomuto_partition(array, low, high, size);

	quicksort_recursive(array, low, pi - 1, size);
	quicksort_recursive(array, pi + 1, high, size);
	}
}
