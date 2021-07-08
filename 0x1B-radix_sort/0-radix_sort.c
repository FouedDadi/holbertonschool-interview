#include "sort.h"

/**
 * countSort - count sort
 * @array: array
 * @size: size of array
 * @exp: exp
 */
void countSort(int *array, size_t size, int exp)
{
int *output = NULL;
int x;
output = malloc(sizeof(int *) * size);
size_t i;
int count[10] = { 0 };
if (!output)
    return;
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (x = size - 1; x >= 0; x--)
{
output[count[(array[x] / exp) % 10] - 1] = array[x];
count[(array[x] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
print_array(array, size);
free(output);
}

/**
 * radix_sort - LSD radix sort algorithm
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	uint i = 1;
	int max = 0, exp = 1;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	while (max)
	{
		countSort(array, size, exp);
		exp *= 10;
		max /= 10;
	}
}
