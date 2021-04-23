#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swap a an b
 * @a: element a
 * @b: element b
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
/**
 * heapify - building a heap
 * @array: array
 * @a: size
 * @b: index
 * @size: size of array
 */
void heapify(int *array, int a, int b, size_t size)
{
    int max = b;
	int left = b * 2 + 1;
	int right = b * 2 + 2;

	if (left < a && array[left] > array[max])
		max = left;

	if (right < a && array[right] > array[max])
		max = right;

	if (max != b)
	{
		swap(&array[b], &array[max]);
		print_array(array, size);
		build_heap(array, a, max, size);
	}
}
}
/**
 * heap_sort - sorting heap
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
int b;
for (b = size / 2 - 1; b >= 0; b--)
heapify(array, size, b, size);
for (b = size - 1; b >= 0; b--)
{
if (array[0] >= array[b])
{
swap(&array[0], &array[b]);
print_array(array, size);
}
heapify(array, b, 0, size);
}
}
