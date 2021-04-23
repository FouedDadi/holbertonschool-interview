#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swap a an b
 * @a: element a
 * @b: element b
 */
void swap(int *i, int *j)
{
int temp = *i;
*i = *j;
*j = temp;
}
/**
 * heapify - building a heap
 * @array: array
 * @a: size
 * @b: index
 * @size: size of array
 */
void build_heap(int *array, int i, int j, size_t size)
{
	int max = j;
	int left = j * 2 + 1;
	int right = j * 2 + 2;

	if (left < i && array[left] > array[max])
		max = left;

	if (right < i && array[right] > array[max])
		max = right;

	if (max != j)
	{
		swap(&array[j], &array[max]);
		print_array(array, size);
		build_heap(array, i, max, size);
	}
}
/**
 * heap_sort - sorting heap
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		build_heap(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		build_heap(array, i, 0, size);
	}
}

