#include "sort.h"
/**
 * shell_sort -  a function that sorts an array of integers in ascending order
 * @array: a pointer to the array to be sorted
 * @size: the size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t n;
	size_t i, j;
	int temp;

	n = 0;
	while (n < size / 3)
	{
		n = n * 3 + 1;
	}

	while (n >= 1)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= n && array[j - n] > temp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = temp;
		}

			print_array(array, size);
		n /= 3;
	}
}


