#include "sort.h"
/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order
 * @array: pointer to the array to be sorted
 * @size: the size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min = 0;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
}
}
