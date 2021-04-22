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
 * build_heap - building a heap
 * @array: array
 * @a: size
 * @b: index
 * @size: size of array
 */
void build_heap(int *array, int a, int b, size_t size)
{
int largest = b;
int left = 2 * b + 1;
int right = 2 * b + 2;
if (left < a && array[left] > array[largest])
largest = left;
if (right < a && array[right] > array[largest])
largest = right;
if (largest != b)
{
swap(&array[b], &array[largest]);
print_array(array, size);
build_heap(array, a, largest, size);
}
}
/**
 * heap_sort - sorting heap
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
for (int b = size / 2 - 1; b >= 0; b--)
build_heap(array, size, b, size);
for (int b = size - 1; b >= 0; b--)
{
if (array[0] >= array[b])
{
swap(&array[0], &array[b]);
print_array(array, size);
}
build_heap(array, b, 0, size);
}
}
