#include "sort.h"

/**
 * swaping - swaps two integers.
 * @x: pointer to the first integer.
 * @y: pointer to the second integer.
 * @arr: array of integers.
 * @size: size of the array.
 */


void swaping(int *x, int*y, size_t size, int *arr)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;

	print_array(arr, size);
}


/**
 * paritition - returns the pivot.
 * @arr: sub array to be sorted.
 * @begin: first indx of sub array.
 * @end: last indx of sub array.
 * @size: size of the array.
 * Return: the index of the pivot.
 */


size_t paritition(int *arr, size_t begin, size_t end, size_t size)
{
	size_t prev, curent, pivot;
	int tmp = 0;

	prev = begin - 1;
	pivot = end;
	for (curent = begin ; curent <= end - 1 ; curent++)
	{
		if (arr[curent] < arr[pivot])
		{
			prev++;
			tmp = arr[curent];
			arr[curent] = arr[prev];
			arr[prev] = tmp;
		}
	}
	prev++;
	swaping(&(arr[end]), &(arr[prev]), size, arr);
	return (prev);
}

/**
 * sortParit - lomuto paritition.
 * @arr: sub array to be sorted.
 * @begin: first index.
 * @end: last index.
 * @size: size of the array.
 */

void sortParit(int *arr, size_t begin, size_t end, size_t size)
{
	size_t pivot;

	if (begin >= end)
		return;
	pivot = paritition(arr, begin, end, size);
	if (pivot > begin)
		sortParit(arr, begin, (pivot - 1), size);
	if (pivot < end)
		sortParit(arr, (pivot + 1), end , size);
}

/**
 * quick_sort - implements the quicksort algorithm by Lomuto paritition.
 * @array: array of integers.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sortParit(array, 0, size - 1, size);
}
