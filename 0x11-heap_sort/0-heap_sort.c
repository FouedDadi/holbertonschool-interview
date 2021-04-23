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
void heapify(int *array, int i, int j, size_t size)
{
int largest = j;
int left = 2 * j + 1;
int right = 2 * j + 2;
if (left < i && array[left] > array[largest])
largest = left;
if (right < i && array[right] > array[largest])
largest = right;
if (largest != j)
{
swap(&array[j], &array[largest]);
print_array(array, size);
heapify(array, i, largest, size);
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
heapify(array, size, i, size);
for (i = size - 1; i >= 0; i--)
{
if (array[0] >= array[i])
{
swap(&array[0], &array[i]);
print_array(array, size);
}
heapify(array, i, 0, size);
}
}
